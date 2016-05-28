var http = require('http');
var url = require('url');

var server = http.createServer((req, res) => {
    console.log(`Connection from `);
    
    var parsed_url = url.parse(req.url, true);
    
    if(parsed_url.pathname != '/servo') {
        res.writeHead(404, {"Content-Type": "text/plain"});
        res.end("fail\n");
        return;
    }
    
    if( !(parsed_url.query.hasOwnProperty('lr') && parsed_url.query.hasOwnProperty('tb')) ) {
        res.writeHead(404, {"Content-Type": "text/json"});
        res.end('{ "result" : "fail" }\n');
        return;
    }
    
    var lr = parsed_url.query.lr;
    
    const spawn = require('child_process').spawn;  
    const servo = spawn('sudo', ['./servo', parsed_url.query.lr, parsed_url.query.tb]);

    servo.on('error', (err) => {
        console.log(err);
    });

    servo.stdout.on('data', (data) => {
        console.log(`stdout: ${data}`);
    });

    servo.stderr.on('data', (data) => {
        console.log(`stderr: ${data}`);
    });
    
    res.writeHead(200, {"Content-Type": "text/plain"});
    res.end("success\n");
    
});

server.listen(3030, "192.168.0.20");

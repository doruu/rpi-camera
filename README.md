# rpi-camera

라즈베리파이로 카메라 제어 프로젝트

## 준비물

### 하드웨어
- 라즈베리파이 2 사용
- 서보모터 2개  sg90
- 포맥스, 순간접착제

### 소프트웨어
- pwm 제어를 위한 c wiringPi
- 웹 인터페이스로 제어를 위해 node 약간
- mjpg-streamer

## 설치

- [wiringPi download/install] 
```
$ sudo apt-get install git-core
$ sudo apt-get update
$ sudo apt-get upgrade
$ git clone git://git.drogon.net/wiringPi
$ cd wiringPi
$ git pull origin
$ cd wiringPi
$ ./build
```
- [node]
```
$ curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```
- [mjpeg-streamer]
```
$ git clone https://github.com/jacksonliam/mjpg-streamer.git
$ cd mjpg-streamer-experimental
$ make
$ sudo make install
```
- [rpi-camera]
```
$ git clone https://github.com/doruu/rpi-camera.git
$ cd rpi-camera
$ gcc servo.cpp -lwiringPi -lstdc++ -o servo
```

## 실행

node 로 웹인터페이스로 제어하기위한 서버실행
```
$ node servo.js
```

화면 스트리밍을 위한 mjpg stereamer 실행
```
$ ./mjpg_streamer -o "output_http.so -w ./www" -i "input_raspicam.so"
``` 

### web interface

http://192.168.0.20:3030/servo?lr=0&tb=0

- lr : 좌우 제어변수 -90 ~ 90 까지 값을 가짐
- tb : 상하 제어변수 -90 ~ 90 까지 값을 가짐

## 다음할일

- 안드로이드용 mpeg-streamer 뷰어 및 VR 적용 카메라제어.


[wiringPi download/install]: <http://wiringpi.com/download-and-install/>
[node]: <https://nodejs.org/en/download/package-manager/#debian-and-ubuntu-based-linux-distributions/>
[mjpeg-streamer]: <https://github.com/jacksonliam/mjpg-streamer>
[rpi-camera]: <https://github.com/jacksonliam/mjpg-streamer>


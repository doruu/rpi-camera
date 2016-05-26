# rpi-camera
카메라모듈, 서보모터를 이용한 카메라 제어 프로젝트.

## 설치

서보모터제어를 위한 wiringPi, 외부에서 제어 를위한 node.js 설치.

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
- [node 설치]
```
$ curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```



[wiringPi download/install]: <http://wiringpi.com/download-and-install/>
[node 설치]: <https://nodejs.org/en/download/package-manager/#debian-and-ubuntu-based-linux-distributions/>
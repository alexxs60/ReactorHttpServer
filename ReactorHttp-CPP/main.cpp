#include<iostream>
#include <signal.h>
#include<unistd.h>
#include <stdlib.h>
#include "TcpServer.h"


int main(int argc, char* argv[]) {
	signal(SIGPIPE, SIG_IGN);
#if 1					//在Linux运行
	if (argc < 3) {
		std::cout << "./a.out port path" << std::endl;
		return -1;
	}
	int portNum = atoi(argv[1]);
	if (portNum <= 0 || portNum > 65535) {
		std::cout << "invalid port" << std::endl;
		return -1;
	}

	if (chdir(argv[2]) == -1) {
		perror("chdir");
		return -1;
	}

	unsigned short port = static_cast<unsigned short>(portNum);
	//切换服务器工作路径
	//chdir(argv[2]);
#else					//用VS在Windows运行
	unsigned short port = 10000;
	chdir("/home/mylinux/HttpTest");
#endif
	//启动服务器
	TcpServer* server = new TcpServer(port,4);
	server->starting();
	return 0;
}
#include <winsock2.h>
#include <iostream>

using namespace std;
int main() {
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if(WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8080);
	addr.sin_family = AF_INET;
	
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	if(connect(sock,(SOCKADDR*)&addr,sizeof(addr))!=0){
		cout<<"Can't connect"<<endl;
		return 1;
	}
	cout<<"Connected"<<endl;
	
	char buff[256]={"autistic crab"};
	send(sock,buff,sizeof(buff),0);
	
	char rcv[256];
	recv(sock,rcv,sizeof(rcv),0);
	cout<<rcv<<endl;
	system("pause");

}

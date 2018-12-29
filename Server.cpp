#include <winsock2.h>
#include <iostream>

using namespace std;
int main(){
	
	WSAData wsdat;
	WORD dllvers = MAKEWORD(2,1);
	if(WSAStartup(dllvers,&wsdat)!=0){
		cout<<"Error"<<endl;
		exit(1);
	}
	SOCKADDR_IN addr;
	int addr_size = sizeof(addr);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	addr.sin_port=htons(8080);
	addr.sin_family = AF_INET;
	
	SOCKET sock  = socket(AF_INET,SOCK_STREAM,0);
	bind(sock,(SOCKADDR*)&addr,sizeof(addr));
	listen(sock,SOMAXCONN);
	
	SOCKET new_sock;
	new_sock=accept(sock,(SOCKADDR*)&addr,&addr_size);
	if(new_sock==0){
		cout<<"Error"<<endl;
	}else{
		cout<<"Succesieve\r\n";
		char buff[256];
		char key[256]={"autistic crab"};
		recv(new_sock,buff,sizeof(buff),0);
		bool b = 1;
		for(int i = 0;i<256;i++){
			if(buff[i]!=key[i]){
				b=0;
			}
		}
		if(b==1){
			char sen[256]={"www.youtube.com/watch?v=LDU_Txk06tM"};
			send(new_sock,sen,sizeof(sen),0);
		}else{
			char sen[256]={"NONONONONONOONO"};
			send(new_sock,sen,sizeof(sen),0);
		}
		system("pause");
	}
	
	return 0;
}
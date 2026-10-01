#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8080
using namespace std;
int main(int argc, const char * argv[])
{
    int serverFd,newSocket;
    ssize_t valread;
    int opt=1;
    sockaddr_in address;
    char buffer[1024]={0};
    char * hello="Hello from server";
    socklen_t addrlen=sizeof(address);
    if((serverFd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        cerr<<"\n SOCKET FAILED";
        exit(EXIT_FAILURE);
    }
    if(setsockopt(serverFd,SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt)))
    {
        cerr<<"\nsetsockopt";
        exit(EXIT_FAILURE);
    }
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(PORT);
    if(bind(serverFd,(sockaddr *) &address,sizeof(address))<0)
    {
        cerr<<"[BIND ERROR]";
        exit(EXIT_FAILURE);
    }
    if(listen(serverFd,3)<0)
    {
        cerr<<"[LISTENING ERROR]";
        exit(EXIT_FAILURE);
    }
    if((newSocket=accept(serverFd,(sockaddr *)&address, & addrlen))<0)
    {
        cerr<<"[ACCEPT ERROR]";
        exit(EXIT_FAILURE);
    }
    valread=read(newSocket,buffer,1024-1);
    cout<<"\n"<<buffer;
    send(newSocket,hello,strlen(hello),0);
    cout<<"\n [MESSAGE SENT FROM SERVER] ";
    close(newSocket);
    close(serverFd);
    return 0;
}
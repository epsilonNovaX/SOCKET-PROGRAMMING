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
    return 0;
}
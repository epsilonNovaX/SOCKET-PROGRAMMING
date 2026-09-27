#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#define PORT 8080
using namespace std;
int main(int argc, const char * argv[])
{
    int serverFd,newSocket;
    ssize_t valread;
    sockaddr_in servAddress;
    char buffer[1024]={0};
    char * hello="Hello from CLIENT";
    return 0;
}
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 8080

void main()
{
	int newSocket = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in servAddr;
	servAddr.sin_family	= AF_INET;
	servAddr.sin_port 	= htons(PORT);
	inet_pton(AF_INET,"127.0.0.1",&servAddr.sin_addr);

	char buf[1024000], filename[10];
	printf("filename : ");
	scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
	while(fgets(buf, sizeof(buf), fp) )
	    sendto(newSocket, buf, strlen(buf) , 0, (struct sockaddr*) &servAddr, sizeof(servAddr));
	fclose(fp);
  }

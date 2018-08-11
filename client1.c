#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>

int main ()
{
printf("begin: %s\n",__FILE__);
int sockfd1;
char ch='A';
struct sockaddr_un client_address;

sockfd1= socket(AF_UNIX, SOCK_STREAM, 0);
if(sockfd1==-1)
{
perror("socket");
}
else
{
printf("socket created\n");
}

client_address.sun_family= AF_UNIX;
strcpy(client_address.sun_path,"server_socket");

if(connect(sockfd1,(struct sockaddr*)&client_address, sizeof(client_address))==-1)
{
perror("connect");
}
else
{
printf("connect successfully\n");
}


write(sockfd1,&ch,1);
read(sockfd1,&ch,1);

printf("char from server %c\n",ch);

close(sockfd1);
printf("end:%s\n", __FILE__);
return 0;
}

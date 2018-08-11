#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{

printf("begin: %s\n",__FILE__);
int sr_sockfd,cl_sockfd,fd;
char ch1;
int len;
int clen;
struct sockaddr_un server_address;
struct sockaddr_un client_address;
unlink("server_socket");

sr_sockfd= socket(AF_UNIX, SOCK_STREAM,0);

if(sr_sockfd==-1)
{
perror("socket");
}
else
{
printf("socket created\n");
}

server_address.sun_family = AF_UNIX;
strcpy(server_address.sun_path, "server_socket");
len = sizeof(server_address);
if(bind(sr_sockfd,(struct sockaddr_un*)&server_address, (len))==-1)
{
perror("bind");
}
else
{
printf("bind done\n");
}

if(listen(sr_sockfd,5)==-1)
{
perror("listen");
}
else
{
printf("listen successfully\n");
}

while(1)
{
cl_sockfd =accept(sr_sockfd,(struct sockaddr*)&client_address, &clen);
if(cl_sockfd==-1)
{
perror("accept");
}
else
{
perror("accept successfully\n");
}

read(cl_sockfd, &ch1, 1);

++ch1;
write(cl_sockfd,&ch1,1);
close(cl_sockfd);
}

printf("end: %s\n",__FILE__);
return 0;
}


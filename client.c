
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    

 // 1.Creation a socket for the client
 int clientSockFD=socket(AF_INET,SOCK_STREAM,0);

 if(clientSockFD!=0)
 {
     printf("Client Socket ID %d:",clientSockFD);
  } 
  else
  {
      printf("Failed to create a socket .\n");
      exit(1);
      }
  

  // 2.Connect the client to a specific server 

  struct sockaddr_in serverAddress;
  memset(&serverAddress,0,sizeof(serverAddress));
  serverAddress.sin_family=AF_INET;
  serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
  serverAddress.sin_port=htons(1984);
  if(connect(clientSockFD,(struct sockaddr*)&serverAddress,sizeof(serverAddress))==0)

  {
         printf("connected successfully \n");
  }
   else
  {
   printf("connected Failed \n");
   exit(1);
  }
  // 3.Send data to the server  
  char buffer[1024]="Bonjour \n";
  send(clientSockFD,buffer,strlen(buffer),0);

   // 4.receive data from the server 
   memset(buffer,0,1024);
   recv(clientSockFD,buffer,1024,0);
   printf("the received data %s \n",buffer);
} 



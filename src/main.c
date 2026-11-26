#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {

  // create TCP socket
  int fd = socket(AF_INET, SOCK_STREAM, 0);

  if (fd == -1) {
    perror("socket");
    return 1;
  }

  // describe the server address
  struct sockaddr_in server = {0};

  server.sin_family = AF_INET;
  server.sin_port = htons(8080);

  inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

  // Establish the TCP connection
  int result = connect(fd, (struct sockaddr *)&server, sizeof(server));

  if (result == -1) {
    perror("connect");
    close(fd);
    return 1;
  }

  printf("TCP connection established!\n");

  // Release the socket.
  close(fd);

  return 0;
}

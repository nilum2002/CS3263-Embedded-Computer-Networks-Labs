#include <stdio.h>
#include <string.h>  // strlen 
#include <sys/socket.h>
#include <arpa/inet.h> // for internet address structures
#include <unistd.h> // write 






int main(int argc, char *argv[]) {
    // define varialbles 
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];


    // Create socket 
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1){
        printf("Could not create socket");
    }puts("Socket created");

    server.sin_family =AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
    
    // bind 
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        // print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");



}
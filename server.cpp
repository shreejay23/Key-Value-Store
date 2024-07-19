#include "server.h"
#include <iostream>
#include <arpa/inet.h>

Server::Server(int port)
{
    this->port = port;
    this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    /*
        AF_INET: Domain. AF_INET indicates that we are using IPv4 addresses.
        SOCK_STREAM: Type of socket. SOCK_STREAM indicates a TCP socket, which provides reliable, connection-oriented communication.
        0: Protocol. 0 indicates that the default protocol for the specified socket type (TCP) should be used.
    Returns: The function returns a file descriptor for the new socket.
    */

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    /*
    To bind our socket with an address and port
        server_address.sin_family = AF_INET;: Sets the address family to AF_INET, indicating that we are using IPv4.
        server_address.sin_port = htons(port);: Sets the port number. htons(port) converts the port number from host byte order to network byte order
        (big-endian). This ensures compatibility with different architectures.
        server_address.sin_addr.s_addr = INADDR_ANY;: Sets the IP address to INADDR_ANY, which means the server will accept connections on any of
        the host's IP addresses.
    */

    bind(this->server_socket, (sockaddr*)&server_address, sizeof(server_address));
    /*
        int bind(int socket_descriptor , const struct sockaddr *address, socklen_t length_of_address);
        Binds our socket to listen and accept connections
    */

    listen(this->server_socket, 4);
    /*
        socket_descriptor: Represents the value of the file descriptor returned by the socket() function.
        back_log: The maximum number of connection requests that can be made to the server by client nodes at a time. The number of requests made
        after the number specified by back_log may cause an error or will be ignored by the server if the options for retransmission are set.
    */
}
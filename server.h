#ifndef SERVER_H
#define SERVER_H

#include <unordered_map>
#include <string>

class Server 
{
    int port;
    int server_socket;
    std::unordered_map<std::string, std::string> store;

    void runServer();
    void handleClient(int client_socket);
    std::string processRequest(const std::string& request);

public:
    void start();
    Server(int port);
};

#endif

// https://www.scaler.com/topics/socket-programming-in-c/
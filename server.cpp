#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

int main (int argc, char* argv[]) {
  if(argc != 2) {
    cout << "invalid number of arguments: call with `./server port`" << endl;
    return 1;
  }

  int port = atoi(argv[1]);

  cout << "running....\n";	
	std::list<ServerSocket> listSocket;  
  try {
    ServerSocket server ( port );

    while ( true ) {

      ServerSocket new_sock;
      server.accept ( new_sock );
			listSocket.push_back (new_sock);

			if(fork() == 0){
				try {
					while ( true ) {
						string data;
						/*Reception data*/
						new_sock >> data;
						/*Affichage data*/
						cout << data << endl;
						/*Envoi reponse*/
						for (std::list<ServerSocket>::iterator it=listSocket.begin(); it != listSocket.end(); ++it){
							ServerSocket sock = *it;
							sock << "test";
						}
						new_sock << data;
					}
				} catch ( SocketException& ) {}
			}
    }
  } catch ( SocketException& e ) {
    cout << "Exception was caught:" << e.description() << "\nExiting" << endl;
  }

  return 0;
}

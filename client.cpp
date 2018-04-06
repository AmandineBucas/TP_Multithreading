#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main (int argc, char* argv[]) {
  if(argc != 3) {
    cout << "invalid number of arguments: call with `./client IP port `" << endl;
    return 1;
  }

  string host = argv[1];
  int port = atoi(argv[2]);
	
	string uti;
	getline(cin, uti);
	

	try {
		ClientSocket client_socket ( host, port );
		while(true){
			string reply;
			getline(cin,reply);
			try {
				client_socket << uti + ": " + reply;
				client_socket >> reply;
			} catch ( SocketException& ) {}

			cout << "We received this response from the server:\n\"" << reply << "\"\n";
		}
	}  catch ( SocketException& e ) {
		cout << "Exception was caught:" << e.description() << endl;
	}
	

  return 0;
}

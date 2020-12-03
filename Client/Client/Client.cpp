#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>

#pragma warning(disable: 4996)

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Ukrainian");
	
	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1487);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";
		return 1;
	}

	std::cout << "Connected!\n";

	while (true) {
		//std::string word;
		std::cout << "Enter the word in English: ";
		//std::cin >> word;
		char msg[256];
		std::cin >> msg;
		//for (int i = 0; i < word.length(); i++) {
		//	msg[i] = word[i];
		//}

		char res[256];

		send(Connection, msg, sizeof(msg), NULL);
		recv(Connection, res, sizeof(res), NULL);
		std::cout << "Слово " << msg << ' ' << "перекладється, як: " << res << '\n';
	}


	system("pause");
	return 0;
}
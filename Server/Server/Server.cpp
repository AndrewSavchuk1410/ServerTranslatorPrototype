#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

std::vector < std::pair <std::string, std::string> > dictionary;

#pragma warning(disable: 4996)

bool correctWord(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!(str[i] >= 'a' && str[i] <= 'z')) return false;
	}
	return true;
}

int findWord(std::string str) {
	for (int i = 0; i < dictionary.size(); i++) {
		if (dictionary[i].first == str) {
			return i;
		}
	}

	return -1487;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Ukrainian");
	{
		dictionary.push_back(std::make_pair("i", "я"));
		dictionary.push_back(std::make_pair("you", "ти, ви, Ви, тебе, тобi, тобою, вами, вас, вам"));
		dictionary.push_back(std::make_pair("she", "вона"));
		dictionary.push_back(std::make_pair("he", "вiн"));
		dictionary.push_back(std::make_pair("it", "воно, йому, його, їй, її"));
		dictionary.push_back(std::make_pair("we", "ми"));
		dictionary.push_back(std::make_pair("they", "вони"));
		dictionary.push_back(std::make_pair("me", "мене, менi, мною"));
		dictionary.push_back(std::make_pair("her", "їй, її"));
		dictionary.push_back(std::make_pair("him", "йому, його"));
		dictionary.push_back(std::make_pair("us", "нами, нам, нас"));
		dictionary.push_back(std::make_pair("them", "їм, їх"));
		dictionary.push_back(std::make_pair("people", "люди"));
		dictionary.push_back(std::make_pair("family", "сiм'я, родина"));
		dictionary.push_back(std::make_pair("man", "чоловiк, людина"));
		dictionary.push_back(std::make_pair("girl", "дiвчина"));
		dictionary.push_back(std::make_pair("boy", "хлопець"));
		dictionary.push_back(std::make_pair("time", "час"));
		dictionary.push_back(std::make_pair("world", "свiт"));
		dictionary.push_back(std::make_pair("programing", "програмування"));
		dictionary.push_back(std::make_pair("table", "стiл, розклад"));
		dictionary.push_back(std::make_pair("university", "унiверситет"));
		dictionary.push_back(std::make_pair("good", "хороший, користь, благо"));
		dictionary.push_back(std::make_pair("death", "смерть"));
		dictionary.push_back(std::make_pair("nobleness", "благородство"));
		dictionary.push_back(std::make_pair("strange", "дивний, незвичайний, дивакуватий"));
		dictionary.push_back(std::make_pair("famous", "вiдомий"));
		dictionary.push_back(std::make_pair("rich", "багатий"));
		dictionary.push_back(std::make_pair("last", "останнiй, тривати"));
		dictionary.push_back(std::make_pair("architecture", "архiтекутра"));
		dictionary.push_back(std::make_pair("age", "вiк"));



	}
	
	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("148.82.2.8");
	addr.sin_port = htons(1487);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConnection == 0) {
		std::cout << "Error #2\n";
	}
	else {
		std::cout << "Client connected!\n";
	}

	while (true) {
		char msg[256];
		recv(newConnection, msg, sizeof(msg), NULL);
		//std::cout << msg;
		bool flag = correctWord(msg);
		
		if (flag == false) {
			char answer[256] = "Error: invalid syntaxis";
			send(newConnection, answer, sizeof(answer), NULL);
		}

		if (flag == true) {
			int index = findWord(msg);
			if (index == -1487) {
				char answer[256] = "Sorry, there is no translation of this word";
				send(newConnection, answer, sizeof(answer), NULL);
			}
			else {
				std::string s = dictionary[index].second;
				char answer[256];
				std::strcpy(answer, s.c_str());
				send(newConnection, answer, sizeof(answer), NULL);
			}
		}
	}

	system("pause");
	return 0;
}


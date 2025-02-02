#pragma once
#include <string>
#include <map>
#include <WinSock2.h>
#include <iostream>
#include <fstream>
#include "Room.h"
#include "Database.h"
class Session
{
public:

	void add(SOCKET s, std::string username);
	void addForbiddenWord(std::string word);
	void removeForbiddenWord(std::string word);
	void messageHandle(SOCKET s);
private:
	std::map<SOCKET, std::string> connections;
	Room room;
	Database db;
private:
	void processMessage(char message[1024], SOCKET s);
	void loadForbiddenWord();
	void saveForbiddenWord();

private:
	std::vector<std::string> splitMessage(char message[]);
	std::vector<std::string> forbiddenWord;
};


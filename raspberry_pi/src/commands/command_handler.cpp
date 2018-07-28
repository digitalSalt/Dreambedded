#include "commands/command_handler.h"

#include <iostream>
#include <string>

static string messageDelimeter = "::";

CommandHandler::CommandHandler() {

}

CommandHandler::~CommandHandler() {

}

void CommandHandler::handle(string msg) {
  cout << msg << endl;
}

void CommandHandler::tokenize(string msg, string tokens[]) {
  int cursor = 0;
  size_t position = msg.find(messageDelimeter);
  string token;

  while (position != string::npos) {
    token = msg.substr(0, position);
    tokens[cursor] = token;
    msg.erase(0, position + messageDelimeter.length());
    position = msg.find(messageDelimeter);
    cursor += 1;
  }

  tokens[cursor] = msg;
}


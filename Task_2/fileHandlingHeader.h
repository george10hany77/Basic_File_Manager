//
// Created by George on 3/2/2024.
//

#ifndef TASK_2_FILEHANDLINGHEADER_H
#define TASK_2_FILEHANDLINGHEADER_H
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <cstring> // For strerror() function
#include <sys/stat.h> // For stat() function
#include <cctype>

using namespace std;

namespace fs = filesystem;

void listDirectory(const string& path);
void viewFile(const string& path);
void writeFile(const string& path);
void createDirectory(const string& parentPath, const string& directoryName);
void copyFile(const string& source, const string& destination);
void moveFile(const string& source, const string& destination);
bool isValidPath(const std::string& path);
void makeFile(string& path, string& name);

#endif //TASK_2_FILEHANDLINGHEADER_H

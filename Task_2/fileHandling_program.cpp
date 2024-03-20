//
// Created by George on 3/2/2024.
//

#include "fileHandlingHeader.h"

void listDirectory(const string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << entry.path().filename() << '\n';
    }
}

void viewFile(const string& path) {
    ifstream file(path);
    if (file.is_open()) {
        cout << "\nContents of " << path << ":\n";
        cout << file.rdbuf();
        file.close();
    } else {
        cerr << "\nError: Unable to open file";
    }
}

void writeFile(const string& path) {
    cout << "Are you removing already existing text ?\n Type Yes or No:";
    string answer;
    getline(cin, answer);
    for (int i = 0; i < answer.length(); ++i) {
        answer[i] = tolower(answer[i]);
    }
    ofstream file;
    if (answer == "yes") {
        file.open(path);
    } else if (answer == "no"){
        file.open(path, ios_base::app);
    } else{
        cerr << "Invalid answer !";
        return;
    }
    if (file.is_open()) {
        cout << "Enter the file's content:";
        string content;
        vector<string> lines;
        while (getline(cin, content) && !content.empty()) {
            lines.push_back(content);
        }
        for (string & s : lines) {
            content.append(s + "\n");
        }
        file << content;
        cout << "The content is wrote successfully";
        file.close();
    } else {
        cerr << "\nError: Unable to open file";
    }
}

void createDirectory(const string& parentPath, const string& directoryName) {
    try {
        fs::create_directory(parentPath + "/" + directoryName);
        cout << "\nDirectory : " + directoryName + " is created successfully";
    } catch (const exception& e) {
        cerr << "\nError: " << e.what() << '\n';
    }
}

void copyFile(const string& source, const string& destination) {

    /////
    string fileName = "";
    for (int i = source.length()-1; i >= 0 && source[i] != '\\'; --i) {
        fileName = source[i] + fileName;
    }
    string newDestination = destination + "\\" + fileName;
    cout << "new dest : " << newDestination;
    fstream file;
    file.open(newDestination, ios::out);
    if (file.is_open()){
        cout << "\nThe file is created successfully";
    } else{
        cerr << "\nThe file is not created";
    }
    file.close();
    /////

    ifstream sourceFile(source, ios::binary);
    if (!sourceFile) {
        cerr << "\nError: Unable to open source file";
        return;
    }

    ofstream destFile(newDestination, ios::binary);
    if (!destFile) {
        cerr << "\nError: Unable to open destination file";
        return;
    }

    destFile << sourceFile.rdbuf();

    sourceFile.close();
    destFile.close();

    cout << "\nFile copied successfully";
}

void moveFile(const string& source, const string& destination) {
    /////
    string fileName;
    for (int i = source.length()-1; i >= 0 && source[i] != '\\'; --i) {
        fileName = source[i] + fileName;
    }
    string newDestination = destination + "\\" + fileName;
    cout << "new dest : " << newDestination;
    fstream file;
    file.open(newDestination, ios::out);
    if (file.is_open()){
        cout << "\nThe file is created successfully";
    } else{
        cerr << "\nThe file is not created";
    }
    file.close();
    /////
    try {
        fs::rename(source, newDestination);
        cout << "\nFile moved successfully";
    } catch (const exception& e) {
        cerr << "\nError: " << e.what() << '\n';
    }
}

void makeFile(string& path, string& name){
    string fullPath = path + "\\" + name + ".txt";
    fstream file;
    file.open(fullPath, ios::out);
    if (file.is_open()){
        cout << "\nThe file : " + name + " is created successfully";
    } else{
        cerr << "\nThe file is not created";
    }
    file.close();
}

bool isValidPath(const string& path) {
    struct stat buffer{};
    if (stat(path.c_str(), &buffer) == 0) {
        return true; // Path exists
    } else {
        cerr << "Error accessing path: " << strerror(errno) << endl;
        return false; // Path does not exist or other error occurred
    }
}
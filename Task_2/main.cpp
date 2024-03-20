#include "fileHandlingHeader.h"

int main() {
    string command;
    string path;

    while (true) {
        cout << "\nEnter command (ls, rf, wf, mkdir, mkf, cpf, mv, exit): ";
        cin >> command;

        if (command == "exit" || command == "mv" || command == "cpf" || command == "mkdir" || command == "mkf" || command == "rf" || command == "wf" || command == "ls") {

            if (command == "exit") {
                break;
            }

            cin.ignore(); // clear the input buffer
            cout << "Enter Path:";
            getline(cin, path);

            cout << path <<"\n";

            if (!isValidPath(path)) {
                cerr << "Invalid Path !";
                continue;
            }

            if (command == "ls") {
                listDirectory(path);
            }

            else if (command == "rf") {
                viewFile(path);
            }

            else if (command == "wf") {
                writeFile(path);
            }

            else if (command == "mkdir") {
                cout << "Enter name:";
                string name;
                getline(cin, name);
                createDirectory(path, name);
            }

            else if (command == "mkf") {
                cout << "Enter name:";
                string name;
                getline(cin, name);
                makeFile(path, name);
            }

            else if (command == "cpf") {
                cout << "Enter destination path:";
                string destination;
                getline(cin, destination);
                copyFile(path, destination);
            }

            else if (command == "mv") {
                cout << "Enter destination path:";
                string destination;
                getline(cin, destination);
                moveFile(path, destination);
            }

        }

        else {
            cerr << "\nInvalid command\n";
        }
    }

    return 0;
}

/*
from "G:\New_folder\f1.txt" , to "G:\New_folder\folder"
*/
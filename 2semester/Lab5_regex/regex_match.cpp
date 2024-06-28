#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

bool isIPAddress(const string& str) {
    regex ip_regex("^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$");
    return regex_match(str, ip_regex);
}

int main() {
    setlocale(LC_ALL, "Rus");
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла input.txt" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла output.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (isIPAddress(line)) {
            outputFile << line << " - Правильный адрес" << endl;
        }
        else {
            outputFile << line << " - Неправильный адрес" << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale.h>
#include <cstring>
using namespace std;

int tre(ifstream &myfile, string line)
{
    getline(myfile, line);
    cout << line;
    return 0;
}

int main () {
    setlocale(LC_ALL, "Russian");
    string line;
    ifstream myfile ("level.txt");

    tre(myfile, line);

    /*if (myfile.is_open())
    {
        getline(myfile, line);
        myfile.close();
    }
    

    char line_char[line.length() + 1];

    for (int x = 0; x < sizeof(line_char); x++) { 
        line_char[x] = line[x]; 
        cout << line_char[x] << ' '; 
    }*/

    system("pause");
    return 0;
}
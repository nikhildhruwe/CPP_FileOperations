#include <iostream>
#include <fstream>
using namespace std;

char* readFile(string);
void writeToFile(string , char *);
int main () {
    char * memblock1, * memblock2;
    string file1 = "file1.txt", file2 = "file2.txt";

    cout << "Before swapping the files contents" << endl;
    memblock1 =  readFile(file1);
    memblock2 =  readFile(file2);

    cout << "\nAfter swaping the files contents" << endl;
    writeToFile(file1, memblock2);
    writeToFile(file2,memblock1); 
}

char* readFile(string fileName){
    fstream file;
    streampos size;
    char * memblock;
    string line;
    
    file.open(fileName, ios::in);
    if (file.is_open()){
        file.seekg(0, ios::end);
        size = file.tellg();
        // cout << size << endl;
        memblock = new char[size];
        file.seekg(0,ios::beg);
        file.read(memblock, size);
        file.seekg(0,ios::beg);
        cout << "Contents of " << fileName << ": " << endl;
        while (getline(file, line))
                  cout << line << endl;
        file.close();
    }
    return memblock;
}

void writeToFile(string fileName, char *memblock){
    fstream file;
    string line;

    file.open(fileName, ios::in |ios::out | ios::trunc);
    if (file.is_open()){
        file << memblock;
        cout << "Contents of " << fileName << ": " << endl;
        file.seekg(0, ios::beg);
        while (getline(file, line))
                  cout << line << endl;
    }
    file.close();
}
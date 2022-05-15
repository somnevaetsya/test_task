#include <iostream>
#include <fstream>

using namespace std;

int nextItem(const int& i,const int& n, const int& m) {
    return 1 + (i + m - 2) % n;
}

int main(int argc, char *argv[]) {
    string fileName = "";
    if (argc == 2) {
        fileName = argv[1];
    } else {
        cout << "Enter filename!" << endl;
        return -1;
    }
    string buf;
    int n, m;
    ifstream input (fileName);
    if (input.is_open())
    {
        if (getline (input,buf)) {
            n = stoi(buf);
        } else {
            cout << "Can`t read from file n";
            return -1;
        }
        if (getline(input, buf)) {
            m = stoi(buf);
        } else {
            cout << "Can`t read from file n";
            return -1;
        }
        input.close();
    }
    else {
        cout << "Unable to open file";
        return -1;
    }    int i = 1;
    while (true) {
        cout << i << " ";
        i = nextItem(i, n, m);
        if (i == 1) {
            break;
        }
    }
    return 0;
}

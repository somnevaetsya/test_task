#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    string fileName = "";
    if (argc == 2) {
        fileName = argv[1];
    } else {
        cout << "Enter filename!" << endl;
        return -1;
    }
    string buf;
    ifstream input (fileName);
    vector<int> items;
    if (input.is_open())
    {
        while (getline(input, buf)) {
            items.push_back(stoi(buf));
        }
    }
    else {
        cout << "Unable to open file";
        return -1;
    }    int i = 1;
    int avg = ceil(accumulate(items.begin(), items.end(), 0.0) / items.size());
    int sum = 0;
    for (auto i : items) {
        sum += abs(avg - i);
    }
    cout << sum << endl;
    return 0;
}

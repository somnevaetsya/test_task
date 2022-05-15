#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;с

int main(int argc, char *argv[]) {
    map<int, string> values;
    string buf;
    ifstream testInput ("tests.json");
    string testString;
    if (testInput.is_open())
    {
       stringstream testStringStream;
       testStringStream << testInput.rdbuf();
       testString = testStringStream.str();
    }
    else {
        cout << "Unable to open file";
        return -1;
    }
    ifstream valuesInput ("values.json");
    string valuesString;
    if (valuesInput.is_open())
    {
        stringstream valuesStringStream;
        valuesStringStream << valuesInput.rdbuf();
        valuesString = valuesStringStream.str();
    }
    else {
        cout << "Unable to open file";
        return -1;
    }
    int currentPos = 0;
    int commaPoint = 0;
    int valuePos = 0;
    int bracketPos = 0;
    while (true) {
        currentPos = testString.find("\"id\":", currentPos);
        if (currentPos == -1) {
            break;
        }
        commaPoint = testString.find(',', currentPos);
        int currentId = stoi(testString.substr(currentPos+5, commaPoint - currentPos - 5));
        values[currentId] = "";
        currentPos++;
    }
    currentPos = 0;
    for (auto& i : values) {
        currentPos = valuesString.find("\"id\": "+to_string(i.first)+",", currentPos);
        if (currentPos == -1) {
            currentPos++;
            continue;
        }
        valuePos = valuesString.find("\"value\":", currentPos);
        bracketPos = valuesString.find('}', valuePos);
        i.second = valuesString.substr(valuePos + 10, bracketPos - valuePos - 14);
        currentPos++;
    }
    currentPos = 0;
    for (auto i : values) {
        currentPos = testString.find("\"id\": "+to_string(i.first)+",", currentPos);
        if (currentPos == -1) {
            currentPos++;
            continue;
        }
        valuePos = testString.find("\"value\":", currentPos);
        testString.insert(valuePos + 10, i.second);
        currentPos++;
    }
    ofstream output;
    output.open ("report.json");
    output << testString;
    output.close();
    return 0;
}

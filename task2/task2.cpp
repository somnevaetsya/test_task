#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    float x,y;
};

int isBelong (const Point& point, const Point& center, const float& radius) {
    float gipotenuza = sqrt(pow(point.x - center.x, 2) + pow(point.y - center.y, 2));
    if (gipotenuza < radius) {
        return 1;
    } else if (gipotenuza > radius) {
        return 2;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    string fileName1 = "";
    string fileName2 = "";
    if (argc == 3) {
        fileName1 = argv[1];
        fileName2 = argv[2];
    } else {
        cout << "Enter filename!" << endl;
        return -1;
    }
    string buf;
    int radius;
    Point circle;
    ifstream input1 (fileName1);
    if (input1.is_open())
    {
        input1 >> buf;
        circle.x = stoi(buf);

        input1 >> buf;
        circle.y = stoi(buf);

        input1 >> buf;
        radius = stoi(buf);
        input1.close();
    }
    else {
        cout << "Unable to open first";
        return -1;
    }
    ifstream input2 (fileName2);
    vector<Point> items;
    if (input2.is_open())
    {
        while (getline(input2, buf)) {
            Point currentPoint;
            currentPoint.x = stof(buf.substr(0, buf.find(' ')));
            currentPoint.y = stof(buf.substr(buf.find(' '), buf.length()-1));
            items.push_back(currentPoint);
        }
        input2.close();
    }
    else {
        cout << "Unable to open first";
        return -1;
    }
    for (auto i : items) {
        cout << isBelong(i, circle, radius) << endl;
    }
    return 0;
}

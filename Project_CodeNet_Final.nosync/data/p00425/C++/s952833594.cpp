#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Dice {
private:
    int top;
    int bottom;
    int north;
    int south;
    int west;
    int east;

public:
    Dice() :
        top   (1),
        bottom(6),
        north (5),
        south (2),
        west  (4),
        east  (3) {}

    int getTop() {
        return top;
    }

    void turnNorth() {
        swap(south, top);
        swap(south, bottom);
        swap(north, bottom);
    }

    void turnSouth() {
        swap(south, bottom);
        swap(south, top);
        swap(north, top);
    }

    void turnWest() {
        swap(east, top);
        swap(east, bottom);
        swap(west, bottom);
    }

    void turnEast() {
        swap(east, bottom);
        swap(east, top);
        swap(west, top);
    }

    void turnRight() {
        swap(south, west);
        swap(south, east);
        swap(north, east);
    }

    void turnLeft() {
        swap(south, east);
        swap(south, west);
        swap(north, west);
    }
};

int main() {
    int n, ans;
    string str;

    while(cin >> n) {
        if(n == 0) break;

        Dice dice;
        ans = 1;

        for (int i=0; i<n; i++) {
            cin >> str;

            if(str == "North")      dice.turnNorth();
            else if(str == "South") dice.turnSouth();
            else if(str == "West")  dice.turnWest();
            else if(str == "East")  dice.turnEast();
            else if(str == "Right") dice.turnRight();
            else if(str == "Left")  dice.turnLeft();

            ans += dice.getTop();
        }

        cout << ans << endl;
    }

    return 0;
}
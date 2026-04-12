#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int output = 1;
        int dice[] = {1, 2, 3, 4, 5, 6, };
        for (int i = 0; i < n; i++) {
            string command;
            cin >> command;
            if (command == "North") {
                dice[0] = dice[1];
                dice[1] = dice[5];
            } else if (command == "East") {
                dice[2] = dice[0];
                dice[0] = dice[3];
            } else if (command == "West") {
                dice[0] = dice[2];
                dice[2] = dice[5];
            } else if (command == "South") {
                dice[1] = dice[0];
                dice[0] = dice[4];
            } else if (command == "Right") {
                dice[1] = dice[2];
                dice[2] = dice[4];
            } else if (command == "Left") {
                dice[2] = dice[1];
                dice[1] = dice[3];
            }
            dice[3] = 7 - dice[2];
            dice[4] = 7 - dice[1];
            dice[5] = 7 - dice[0];
            output += dice[0];
        }
        cout << output << endl;
    }
}
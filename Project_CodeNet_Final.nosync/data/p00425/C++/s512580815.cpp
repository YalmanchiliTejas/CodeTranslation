

#include <iostream>

using namespace std;

int main()
{
    int dice_front[3] = {};
    int n, total = 0, temp;
    while(cin >> n && n != 0) {
        dice_front[0] = 1; dice_front[1] = 2; dice_front[2] = 3;
        total = dice_front[0];
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            if(s == "North") {
                temp = dice_front[1];
                dice_front[1] = 7 - dice_front[0];
                dice_front[0] = temp;
            } else if (s == "East") {
                temp = dice_front[0];
                dice_front[0] = 7 - dice_front[2];
                dice_front[2] = temp;
            } else if (s == "West") {
                temp = dice_front[2];
                dice_front[2] = 7 - dice_front[0];
                dice_front[0] = temp;
            } else if (s == "South") {
                temp = dice_front[0];
                dice_front[0] = 7 - dice_front[1];
                dice_front[1] = temp;
            } else if (s == "Right") {
                temp = dice_front[2];
                dice_front[2] = 7 - dice_front[1];
                dice_front[1] = temp;
            } else if (s == "Left") {
                temp = dice_front[1];
                dice_front[1] = 7 - dice_front[2];
                dice_front[2] = temp;
            }
            
            total += dice_front[0];
        }
        
        cout << total << endl;
    }
}


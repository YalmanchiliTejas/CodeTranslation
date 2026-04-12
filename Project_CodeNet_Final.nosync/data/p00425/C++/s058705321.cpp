#include <iostream>
#include <string>
using namespace std;

int dice[6] = {1, 2, 3, 4, 5, 6};

void mv(string cmd)
{
    int d[6];
    
    for(int i=0;i < 6;++i) d[i] = dice[i];

    if (cmd == "North") {
        dice[0] = d[1];
        dice[1] = d[5];
        dice[4] = d[0];
        dice[5] = d[4];
    } else if (cmd == "East") {
        dice[0] = d[3];
        dice[2] = d[0];
        dice[3] = d[5];
        dice[5] = d[2];
    } else if (cmd == "West") {
        dice[0] = d[2];
        dice[2] = d[5];
        dice[3] = d[0];
        dice[5] = d[3];
    } else if (cmd == "South") {
        dice[0] = d[4];
        dice[1] = d[0];
        dice[4] = d[5];
        dice[5] = d[1];
    } else if (cmd == "Right") {
        dice[1] = d[2];
        dice[2] = d[4];
        dice[3] = d[1];
        dice[4] = d[3];
    } else if (cmd == "Left") {
        dice[1] = d[3];
        dice[2] = d[1];
        dice[3] = d[4];
        dice[4] = d[2];
    }
}

int main()
{
    int n;
    while (cin >> n && n) {
        int ans = 1; string cmd;
        
        for(int i=0; i < n; ++i) {
            cin >> cmd;
            mv(cmd);
            ans += dice[0];
        }

        cout << ans << endl;

        for(int i=0;i < 6;++i) dice[i] = i+1;
    }

    return 0;
}
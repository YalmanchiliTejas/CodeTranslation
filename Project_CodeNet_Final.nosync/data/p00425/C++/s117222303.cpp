#include <bits/stdc++.h>

using namespace std;

int main()
{
    int move_num;
    
    while (cin >> move_num) {
        if (move_num == 0) break;

        vector<int> dice = {1, 2, 3, 4, 5, 6};
        int ans = 1;
        
        for (int i = 0; i < move_num; ++i) {
            string direction;

            cin >> direction;

            int temp;

            switch (direction[0]) {
                case 'N':
                    temp = dice[0];
                    dice[0] = dice[1];
                    dice[1] = dice[5];
                    dice[5] = dice[4];
                    dice[4] = temp;
                    
                    ans += dice[0];
                    break;
                case 'S':
                    temp = dice[0];
                    dice[0] = dice[4];
                    dice[4] = dice[5];
                    dice[5] = dice[1];
                    dice[1] = temp;
                    
                    ans += dice[0];

                    break;
                case 'E':
                    temp = dice[0];
                    dice[0] = dice[3];
                    dice[3] = dice[5];
                    dice[5] = dice[2];
                    dice[2] = temp;
                    
                    ans += dice[0];
                    break;
                case 'W':
                    temp = dice[0];
                    dice[0] = dice[2];
                    dice[2] = dice[5];
                    dice[5] = dice[3];
                    dice[3] = temp;
                    
                    ans += dice[0];
                    break;
                case 'L':
                    temp = dice[1];
                    dice[1] = dice[3];
                    dice[3] = dice[4];
                    dice[4] = dice[2];
                    dice[2] = temp;
                    
                    ans += dice[0];
                    break;
                case 'R':
                    temp = dice[1];
                    dice[1] = dice[2];
                    dice[2] = dice[4];
                    dice[4] = dice[3];
                    dice[3] = temp;
                    
                    ans += dice[0];
                    break;
                default:
                    break;
            }

        }

        cout << ans << endl;
    }
    
    return 0;
}
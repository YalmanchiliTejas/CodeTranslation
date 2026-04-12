#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

template<typename T>
inline T in(){T tmp; cin >> tmp; return tmp;}

int main()
{
    int n;

    while (scanf("%d", &n), n){
        int dice[6] = {1, 2, 6, 5, 4, 3};
        int sum = 1;

        while (n-- > 0){
            string s = in<string>();

            if (s == "North"){
                int tmp = dice[0];
                for (int i = 0; i < 3; i++) dice[i] = dice[i + 1];
                dice[3] = tmp;
            }
            else if (s == "South"){
                int tmp = dice[3];
                for (int i = 3; i > 0; i--) dice[i] = dice[i - 1];
                dice[0] = tmp;
            }
            else if (s == "East"){
                int tmp = dice[4];
                dice[4] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[0];
                dice[0] = tmp;
            }
            else if (s == "West"){
                int tmp = dice[5];
                dice[5] = dice[2];
                dice[2] = dice[4];
                dice[4] = dice[0];
                dice[0] = tmp;
            }
            else if (s == "Right"){
                int tmp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[4];
                dice[4] = tmp;
            }
            else if (s == "Left"){
                int tmp = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[3];
                dice[3] = dice[5];
                dice[5] = tmp;
            }
            sum += dice[0];
        }
        printf("%d\n", sum);
    }

    return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main() {
    int n=0, remain=0, player=0;
    int plnum=0;
    string num="";
    while (1) {
        bool bo[1001] = { false };
        plnum = 0;
        cin >> player >> n;
        if (player == 0 && n == 0)break;
        remain = player;
        for (int i = 1; i <= n; ++i) {
            cin >> num;
            if (remain == 1)continue;
            plnum++;
            if (plnum == player + 1)plnum = 1;
            while (bo[plnum]) {
                plnum++;
                if (plnum == player + 1)plnum = 1;
            }
            if (i % 3 == 0 || i % 5 == 0) {
                if (i % 15 == 0 && num != "FizzBuzz") {
                    bo[plnum] = true;
                    remain--;
                }
                else if (i%15!=0&&i % 3 == 0 && num != "Fizz") {
                    bo[plnum] = true;
                    remain--;
                }
                else if (i%15!=0&&i % 5 == 0 && num != "Buzz") {
                    bo[plnum] = true;
                    remain--;
                }
            }
            else if(num[0]<'0'||'9'<num[0]){
                bo[plnum] = true;
                remain--;
            }
            else {
                if (stoi(num) != i) {
                    bo[plnum] = true;
                    remain--;
                }
            }
        }
        bool flag = false;
        for (int i = 1; i <= player; ++i) {
            if (!bo[i]) {
                cout << (flag ? " " : "") << i;
                flag = true;
            }
        }cout << endl;
    }
    return 0;
}

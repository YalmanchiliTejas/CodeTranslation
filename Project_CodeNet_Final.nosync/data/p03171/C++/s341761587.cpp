// L - Deque  https://atcoder.jp/contests/dp/tasks/dp_l
/* 入力例
4
10 80 90 30
// →出力 10
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int a[3000];
long long int mem[3000][3000];
int memflag[3000][3000];

long long int dp(int l, int r) {
    if(memflag[l][r] == 1) {
        return mem[l][r];
    } else if(l == r) {
        mem[l][r] = a[l];
        memflag[l][r] = 1;
        return mem[l][r];
    } else {
        mem[l][r] = max(dp(l + 1, r) * (-1) + a[l], dp(l, r - 1) * (-1) + a[r]);
        memflag[l][r] = 1;
        return mem[l][r];
    }
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        for(int j = 0; j < N; j++) {
            memflag[i][j] = 0;
        }
    }

    cout << dp(0, N - 1);
    cout << "";
    return 0;
}

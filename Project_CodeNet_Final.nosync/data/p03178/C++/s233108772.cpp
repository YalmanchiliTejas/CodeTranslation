#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[100000][100][2] = {};

void add(int &a, int b) {
    a = (a + b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string k;
    int d;
    cin >> k >> d;

    for (int kk=0; kk<k[0]-'0'; kk++)
        dp[0][kk%d][0]++;
    dp[0][(k[0]-'0')%d][1]++;
    for (int i=0; i<k.length()-1; i++)
        for (int j=0; j<d; j++) {
            for (int kk=0; kk<10; kk++)
                add(dp[i+1][(j+kk)%d][0], dp[i][j][0]);
            for (int kk=0; kk<k[i+1]-'0'; kk++)
                add(dp[i+1][(j+kk)%d][0], dp[i][j][1]);
            add(dp[i+1][(j+k[i+1]-'0')%d][1], dp[i][j][1]);
        }

    add(dp[k.length()-1][0][0], dp[k.length()-1][0][1]);
    cout << (dp[k.length()-1][0][0] + MOD - 1) % MOD << "\n";

    return 0;
}

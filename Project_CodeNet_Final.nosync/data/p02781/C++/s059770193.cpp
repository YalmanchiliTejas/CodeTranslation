#include <bits/stdc++.h>
using namespace std;


const int L = 100;
int dp[L][10][4];
string n;
int k;


void init()
{
    dp[0][0][0] = 1;
    for (int d = 1; d <= 9; d++) dp[0][d][1] = 1;
    for (int i = 1; i < L; i++) {
        for (int d = 0; d <= 9; d++)
            for (int dd = 0; dd <= 9; dd++)
                for (int c = 0; c <= 3; c++) {
                    int t = (d == 0) ? 0 : 1;
                    if (t + c <= 3) dp[i][d][t + c] += dp[i - 1][dd][c];
                }
    }
}


void solve()
{
    int len = n.size();
    int krest = k;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int d = n[i] - '0';
        int jmax = (i == len - 1) ? d : d - 1;
        for (int j = 0; j <= jmax; j++) ans += dp[len - 1 - i][j][krest];
        if (d > 0) krest--;
        if (krest < 0) break;
    }
    cout << ans << endl;
}


int main()
{
    cin >> n >> k;
    init();
    solve();
    return 0;
}

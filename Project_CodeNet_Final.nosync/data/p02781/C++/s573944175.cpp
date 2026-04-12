#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int dp[105][4][2];

int main(int argc, char const *argv[])
{
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;
    dp[0][0][0] = 1;
    rep(i,n)rep(j,4)rep(l,2) {
        int nd = s[i] - '0';
        rep(d,10) {
            int ni = i + 1, nj = j, nl  = l;
            if (d != 0) nj ++;
            if (nj > k) continue;
            if (l == 0)
            {
                if (d > nd) continue;
                if (d < nd) nl = 1;
            }
            dp[ni][nj][nl] += dp[i][j][l];
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int M = 1e4 + 3;
const int MOD = 1e9 + 7;
string k;
int n, d;
int dp[M][102][2];

int solve (int i, int s, bool b) {
    if (i >= n) {
        if (!s) return 1;
        return 0;
    }
    int &ret = dp[i][s][b];
    if (ret != -1) return ret;
    ret = 0;
    for (int add = 0; add <= (b ? 9 : k[i]-'0'); add++) {
        ret = (ret + solve (i+1, (s+add)%d , b||(add<k[i]-'0'))) % MOD;
    }
    return ret;

}

int main () {
    cin >> k >> d;
    n = k.size();
    memset(dp, -1, sizeof dp);
    cout << (solve (0, 0, 0)-1+MOD)%MOD;
}

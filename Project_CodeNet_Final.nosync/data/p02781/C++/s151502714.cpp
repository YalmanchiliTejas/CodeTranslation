#include <bits/stdc++.h>

using namespace std;

int n, m;
long long dp[100][3][3];
string s;

long long rec(int pos, int flag, int k) {
    if (pos == n) {
        return k == m;
    }
    if (k == m) {
        return dp[pos][flag][k] = 1;
    }
    long long &res = dp[pos][flag][k];
    if (res != -1) return res;
    res = 0;
    int border = flag ? 9 : s[pos];
    for (int digit = 0; digit <= border; digit++) {
        int nflag = flag | (digit < border);
        int nk = k + (digit != 0);
        res += rec(pos + 1, nflag, nk);
    }
    return res;
}

void solve() {
    cin >> s >> m;
    for (auto &x : s) x -= '0';
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0, 0);
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
}

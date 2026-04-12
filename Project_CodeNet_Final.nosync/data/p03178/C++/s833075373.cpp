#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
long long dp[10001][100][2][2];
vector<int> dig;
long long d;

long long rec(int pos, int rem, int st, int f) {
    if (pos == -1) {
        if (rem == 0 && st)
            return 1;
        else
            return 0;
    }
    long long &res = dp[pos][rem][st][f];
    if (res != -1)
        return res;
    int lmt = f ? 9 : dig[pos];
    long long ans = 0;
    for (int i = 0; i <= lmt; i++) {
        int nf = f | (i < lmt);
        int nst = st | (i > 0);
        ans += rec(pos - 1, (rem + i) % d, nst, nf);
        if (ans > MOD)
            ans -= MOD;
    }
    return res = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s >> d;
    int n = s.size();
    dig = vector<int> (n);
    for (int i = 0; i < n; i++) {
        dig[n - 1 - i] = s[i] - '0';
    }
    cout << rec(n - 1, 0, 0, 0);
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
    return 0;
}

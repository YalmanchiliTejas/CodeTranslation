#pragma optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 2 * (int)1e5 + 100;
int n, m;
string s;
int dp[maxN][2][2];
int f[maxN];
int pref[maxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m >> s;
    if (s[0] == 'B') {
        for (int i = 0; i < m; i++) {
            s[i] = 'R' + 'B' - s[i];
        }
    }
    while (!s.empty() && s.back() == 'R') s.pop_back();
    if (s.empty()) {
        // 1 - B
        // 0 - R
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == 1 && j == 1) continue;
                dp[0][i][j] = 1;
            }
        }
        for (int i = 0; i + 1 <= n - 2; i++) {
            for (int was = 0; was < 2; was++) {
                for (int last = 0; last < 2; last++) {
                    for (int nlast = 0; nlast < 2; nlast++) {
                        if (nlast == 1 && last == 1) continue;
                        dp[i + 1][was][nlast] = sum(dp[i + 1][was][nlast], dp[i][was][last]);
                    }
                }
            }
        }
        int sm = 0;
        for (int last = 0; last < 2; last++) {
            for (int cur = 0; cur < 2; cur++) {
                if (last == 1 && cur == 1) continue;
                sm = sum(dp[n - 2][last][cur], sm);
            }
        }
        cout << sm << '\n';
        return 0;
    }
    int limR = 0;
    int cnt = 0;
    m = s.size();
    for (int i = 0; i < m; i++) {
        if (s[i] == 'B') break;
        cnt++;
    }
    if (cnt % 2 == 0) {
        limR = cnt + 1;
    }
    else {
        limR = cnt;
    }
    assert(s[m - 1] == 'B');
    for (int i = 0; i + 1 < m; i++) {
        if (s[i] == 'B' && s[i + 1] != 'B') {
            int tot = 0;
            for (int j = i + 1; ; j++) {
                if (s[j] == 'B') break;
                tot++;
            }
            if (tot % 2 == 0) continue;
            limR = min(limR, tot);
        }
    }
  //  cout << limR << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            pref[i][j] = sum(pref[i][j], pref[i - 1][j]);
        }
        if (i % 2 == 1 && i <= limR) f[i] = sum(f[i], 1);
        if (i >= 2) {
            f[i] = sum(f[i], sub(pref[i - 2][i % 2], pref[max(0, i - limR - 2)][i % 2]));
        }
        pref[i][i % 2] = sum(pref[i][i % 2], f[i]);
    }
    int ans = 0;
    for (int red1 = 1; red1 <= limR; red1 += 2) {
        if (n == red1 + 1) {
            ans = sum(ans, n);
            continue;
        }
        int le = n - red1 - 2;
        if (le < 0) continue;
        ans = sum(ans, mult(f[le], red1 + 1));
    }
    cout << ans;
    return 0;
}
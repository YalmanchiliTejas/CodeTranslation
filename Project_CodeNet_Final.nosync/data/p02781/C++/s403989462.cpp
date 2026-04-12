#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int ctoi(char c) { return int(c - '0'); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    int k;
    cin >> str >> k;

    int n = str.size();
    vector<vll> dp0(n + 1, vll(k + 2, 0)), dp1(n + 1, vll(k + 2, 0));
    dp0[0][0] = 1;

    rep(i, 0, n) {
        rep(j, 0, k + 1) {
            if (str[i] == '0') {
                dp0[i + 1][j] += dp0[i][j];
                dp1[i + 1][j] += dp1[i][j];
                dp1[i + 1][j + 1] += 9 * dp1[i][j];
            } else {
                dp0[i + 1][j + 1] += dp0[i][j];
                dp1[i + 1][j] += dp0[i][j];
                dp1[i + 1][j + 1] += (ctoi(str[i]) - 1) * dp0[i][j];
                dp1[i + 1][j] += dp1[i][j];
                dp1[i + 1][j + 1] += 9 * dp1[i][j];
            }
        }
    }

    cout << dp0[n][k] + dp1[n][k] << endl;

    return 0;
}
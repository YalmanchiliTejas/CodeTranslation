#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<29;
const ll LINF = 1LL<<58;
const int mod = 1000000007;

ll dp[110][2][110];

void solve() {
    int k, n;
    string s;
    cin >> s >> k;
    n = s.size();
    dp[0][0][0] = 1;
    rep(i, n) {
        int D = s[i]-'0';
        rep(j, 2) {
            rep(x, 105) {
                rep(d, (j ? 10 : D + 1)) {
                    dp[i + 1][j || d < D][x + (d == 0)] += dp[i][j][x];
                }
            }
        }
    }
    cout << dp[n][0][n-k] + dp[n][1][n-k] << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

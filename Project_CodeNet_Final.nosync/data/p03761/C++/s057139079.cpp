# include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
    ll n; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    string ans;
    for (char c = 'a'; c <= 'z'; c++) {
        ll res = 1e18;
        rep(i, n) {
            ll cnt = 0;
            rep(j, len(s[i])) {
                if (s[i][j] == c) ++cnt;
            }
            res = min(res, cnt);
        }
        rep(i, res) ans += c;
    }
    cout << ans << endl;
}
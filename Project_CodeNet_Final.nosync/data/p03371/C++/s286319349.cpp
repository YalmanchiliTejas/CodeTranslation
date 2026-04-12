#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = LONG_LONG_MAX;
    rep(i, (x + y) * 2 + 1) {
        ll ac = max(0LL, x - i / 2);
        ll bc = max(0LL, y - i / 2);
        ll tmp = ac * a + bc * b + i * c;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}

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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    while(true) {
        bool f = false;
        rep(i, n) {
            if (a[i] >= n) {
                f = true;
                break;
            }
        }
        if (!f) {
            break;
        }
        rep(i, n) {
            if (a[i] < n) continue;
            ll c = max(0LL, a[i] / n);
            ans += c;
            a[i] %= n;
            rep(j, n) {
                if (i == j) continue;
                a[j] += c;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

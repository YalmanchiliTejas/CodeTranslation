#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

ll op(ll a, ll b) { return max(a, b); }
ll e() { return -1; }
ll target;
bool f(ll v) { return v < target; };

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    segtree<ll, op, e> st(a);
    rep(i, q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x, v;
            cin >> x >> v;
            x--;
            st.set(x, v);
        }
        else if (t == 2) {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << st.prod(l, r) << endl;
        }
        else {
            ll x;
            cin >> x >> target;
            x--;
            cout << (st.max_right<f>(x) + 1) << endl;
        }
    }
    return 0;
}

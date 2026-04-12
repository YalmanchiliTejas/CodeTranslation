#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll= long long;
using ld= long double;
using vl= vector<ll>;
using vd= vector<ld>;
using vs= vector<string>;
using vb= vector<bool>;
using vvl= vector<vector<ll>>;
using vvd= vector<vector<ld>>;
using vvs= vector<vector<string>>;
using vvb= vector<vector<bool>>;
using pll= pair<ll, ll>;
constexpr ll mod= 1e9 + 7;
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for(ll(i)= 0; (i) < (n); (i)++)
#define REPS(i, n) for(ll(i)= 1; (i) <= (n); (i)++)
#define RREP(i, n) for(ll(i)= (n - 1); (i) >= 0; (i)--)
#define RREPS(i, n) for(ll(i)= (n); (i) > 0; (i)--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())
#define YES(n) ((n) ? "YES" : "NO")
#define Yes(n) ((n) ? "Yes" : "No")
#define yes(n) ((n) ? "yes" : "no")

template <class T>
inline void chmin(T &a, T b) {
    if(a > b) { a= b; }
}

template <class T>
inline void chmax(T &a, T b) {
    if(a < b) { a= b; }
}

ll op(ll a, ll b) { return max(a, b); }
ll e() { return -1; }
ll target;
bool f(ll x) { return (x < target); }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    ll N, Q;
    cin >> N >> Q;
    segtree<ll, op, e> seg(N);
    REP(i, N) {
        ll x;
        cin >> x;
        seg.set(i, x);
    }
    REP(i, Q) {
        ll T;
        cin >> T;
        if(T == 1) {
            ll x, v;
            cin >> x >> v;
            x--;
            seg.set(x, v);
        } else if(T == 2) {
            ll L, R;
            cin >> L >> R;
            L--;
            cout << seg.prod(L, R) << "\n";
        } else {
            ll x, v;
            cin >> x >> v;
            target= v;
            x--;
            cout << seg.max_right<f>(x) + 1 << "\n";
        }
    }
}
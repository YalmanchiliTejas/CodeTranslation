#include <atcoder/all>
#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

int x, v, l, r;

bool f(int x) { return x < v; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    atcoder::segtree<int, op, e> seg(a);

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            cin >> x >> v;
            x--;
            seg.set(x, v);
        }
        if(t == 2) {
            cin >> l >> r;
            cout << seg.prod(l - 1, r) << "\n";
        }
        if(t == 3) {
            cin >> x >> v;
            x--;
            cout << seg.max_right<f>(x) + 1 << "\n";
        }
    }

    return 0;
}
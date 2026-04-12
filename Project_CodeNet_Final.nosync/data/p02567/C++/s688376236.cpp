#pragma region head
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vv = vector<vector<T>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrepi(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define bit(n) (1LL << (n))
template <class T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = 1002003004;
const ll LINF = 1002003004005006007ll;
struct preprocess {
    preprocess() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} ____;
#pragma endregion head

#pragma region library
#pragma endregion library
int f(int a, int b) {
    return max(a, b);
}
int e() {
    return -1;
}
int val;
bool check(int a) {
    return a < val;
}
int main() {
    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    segtree<int, f, e> sg(a);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            sg.set(x, y);
        } else if (t == 2) {
            cout << sg.prod(x, y) << '\n';

        } else if (t == 3) {
            val = y;
            cout << sg.max_right<check>(x)+1 << '\n';
        }
    }
}
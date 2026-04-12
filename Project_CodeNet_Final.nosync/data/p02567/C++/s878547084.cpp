#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep2(i,m,n) for (int i = (m); i < (n); ++i)
#define rep(i,n) rep2(i,0,n)
#define debug(x) cerr << x << endl
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> P;
template<typename T> struct V : vector<T> { using vector<T>::vector; };
V() -> V<int>;
V(size_t) -> V<int>;
template<typename T> V(size_t, T) -> V<T>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1<<30;
const ll LINF = 1LL<<61;
const ll MOD = 1000000007;

ll op(ll lh, ll rh) { return max(lh, rh); }
ll e() { return -1; }
int rh;
bool f(ll lh) { return lh < rh; }

int main()
{
    int n, q;
    cin >> n >> q;
    segtree<ll, op, e> seg(n);
    rep(i,n)
    {
        int a;
        cin >> a;
        seg.set(i,a);
    }
    rep(i,q)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int p, x;
            cin >> p >> x;
            p--;
            seg.set(p,x);
        }
        else if(t == 2)
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l,r) << "\n";
        }
        else if(t == 3)
        {
            int v;
            cin >> v >> rh;
            v--;
            cout << seg.max_right<f>(v) + 1 << "\n";
        }
        
    }

    return 0;
}

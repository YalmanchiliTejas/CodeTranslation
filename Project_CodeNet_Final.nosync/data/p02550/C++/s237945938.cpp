#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define endl '\n'
const int inf = 1000000007;
const ll INF = 1e18;
int mod = 998244353;
// int mod = 1000000007;
const double eps = 1e-8;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template<typename T, typename U> T pow_(T a, U b) { return b ? pow_(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
ll modpow(ll a, ll b, ll _mod) { return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1; }
template<class T, class U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> ostream& operator << (ostream& os, const vector<T>& vec) { rep(i, sz(vec)) { if (i) os << " "; os << vec[i]; } return os; }
template<class T> ostream& operator << (ostream& os, const set<T>& s) { for (auto si : s) os << si << " "; return os; }
template<typename T> inline istream& operator >> (istream& is, vector<T>& v) { rep(j, sz(v)) is >> v[j]; return is; }
template<class T, class T2> inline void add(T &a, T2 b) { (a += (b % mod + mod)) %= mod; }
template<class T> void operator += (vector<T>& v, vector<T> v2) { rep(i, sz(v2)) v.eb(v2[i]); }

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int T;
    T = 1;
    while (T--) solve();
}

void solve() {
    ll n;
    cin >> n;
    int x, m;
    cin >> x >> m;
    
    set<ll> s;
    vector<ll> v, v2;
    
    ll x2 = x;
    rep(i, m) {
        s.emplace(x2);
        (x2 *= x2) %= m;
        if (s.count(x2)) {
            rep(j, m) {
                v2.eb(x2); // ループ部分だけ
                (x2 *= x2) %= m;
                if (x2 == v2[0]) break;
            }
            x2 = x;
            rep(j, m) {
                if (x2 == v2[0]) break;
                v.eb(x2);
                (x2 *= x2) %= m;
            }
            break;
        }
    }
    // cerr << v << endl << v2 << endl;
    
    ll ans = 0;
    rep(i, sz(v)) {
        ans += v[i];
        --n;
        if (n == 0) break;
    }
    // cerr << n << " " << ans << endl;
    ans += n / sz(v2) * accumulate(all(v2), 0LL);
    n %= sz(v2);
    rep(i, n) ans += v2[i];
    cout << ans << endl;
}



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vs = vector<string>;
using vp = vector<pii>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (ll)((x).size())
#define all(x) (x).begin(), (x).end()
#define each(a, x) for (auto&& a : (x))
#define _overload3(_1, _2, _3, name, ...) name
#define rep1(n) rep2(_, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, n) for (ll i = (a); i < (n); ++i)
#define rep(...) _overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
template<typename T> inline void print(const T& x) {cout << x << "\n";}
template<typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
template<typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
struct Init {Init() {cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(10);}} init;

int main() {
    ll n;
    cin >> n;
    vi a(n);
    ll s = 0;
    rep(i,n) {
        cin >> a[i];
        s += a[i];
        s %= MOD;
    }
    ll ans = 0;
    rep(i,n-1) {
        s -= a[i];
        if (s < 0) s += MOD;
        ans += a[i] * s;
        ans %= MOD;
    }
    print(ans);
}
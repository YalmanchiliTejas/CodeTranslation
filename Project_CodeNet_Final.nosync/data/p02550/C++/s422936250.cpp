#include <bits/stdc++.h>
#include <algorithm>
// #include <atcoder/all>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i, m, n) for (ll(i) = (ll)(m); i < (ll)(n); ++i)
#define REP2(i, m, n) for (ll(i) = (ll)(n)-1; i >= (ll)(m); --i)
#define rep(i, n) REP(i, 0, n)
#define rep2(i, n) REP2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> inline void print(T x) { cout << x << '\n'; }
template <class T> bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 998244353;
struct mint {
    ll x;  // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// v ector<long long> v(n), c(n);
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
// vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1,
// vector<int>(k+1, 0)));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> a;
    map<ll,ll> cnt;
    a.push_back(x);
    cnt[x]++;
    ll cycle_first = -1;
    REP(i,1,n) {
        ll tmp = a[i-1]*a[i-1];
        tmp %= m;
        if (cnt[tmp] > 0) {
            cycle_first = tmp;
            break;
        }
        cnt[tmp]++;
        a.push_back(tmp);
    }
    vector<ll> b,cy;
    bool f = false;
    rep(i,a.size()) {
        if (a[i] == cycle_first) {
            f = true;
        }
        if (f) {
            cy.push_back(a[i]);
        } else {
            b.push_back(a[i]);
        }

    }
    ll lenb = b.size();
    ll lency = cy.size();
    ll cy_cnt = 0;
    ll cy_sum = 0;
    rep(i,lency) cy_sum += cy[i];
    ll res = 0;
    if (lenb >= n) {
        rep(i,lenb) res += a[i];
    } else {
        rep(i,lenb) res += a[i];
        n -= lenb;
        if (lency != 0) {
            cy_cnt = n/lency;
            n %= lency;
        }
        if (n != 0) {
            rep(i,n) {
                res += cy[i];
            }
        }
        res += cy_sum*cy_cnt;

    }
    print(res);



}

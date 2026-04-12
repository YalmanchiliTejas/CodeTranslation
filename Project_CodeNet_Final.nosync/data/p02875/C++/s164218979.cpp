// May this submission get accepted!

#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define STEP(i, is, ie, step) for (long long i=(is), i##_end=(ie), i##_step = (step); i<=i##_end; i+=i##_step)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) do { cerr << "[DEBUG] " #q ": ["; REP(i, (q).size()) { cerr << (q)[i] << (i == i_len-1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; } while (false)
template<class T> T gcd(T a, T b) { if (a < b) std::swap(a, b); while (b) std::swap(a %= b, b); return a; }
template<class T> T lcm(const T a, const T b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
#define DANCE_ long
#define ROBOT_ unsigned
#define HUMAN_ signed
#define CHOKUDAI_ const
using  ll = DANCE_ HUMAN_ DANCE_;
using ull = DANCE_ ROBOT_ DANCE_;
using cll = DANCE_ DANCE_ CHOKUDAI_;
using  ld = long double;
using namespace std;

// モジュール

// 剰余演算
constexpr ll pdiv = 998244353LL; // 10^9+7
ll powll(ll a, ll n) {
    ll result = 1;
    ll base = a;
    ll mask = 1;
    while (mask <= n) {
        if (n & mask) (result *= base) %= pdiv;
        mask <<= 1;
        (base *= base) %= pdiv;
    }
    return result;
}

inline ll invll(ll a) { return powll(a, pdiv-2); }

vector<ll> fac_cache = {1}, invfac_cache = {1};
void make_fac_cache(ll a) {
    ll old_max = fac_cache.size() - 1;
    if (a > old_max) {
        fac_cache   .resize(a+1);
        invfac_cache.resize(a+1);
        for (ll i = old_max + 1; i <= a; i++) {
            fac_cache[i] = fac_cache[i-1] * i % pdiv;
        }
        invfac_cache[a] = invll(fac_cache[a]);
        for (ll i = a-1; i > old_max; i--) {
            invfac_cache[i] = invfac_cache[i+1] * (i + 1) % pdiv;
        }
    }
}

inline ll    facll(ll a) { make_fac_cache(a); return fac_cache[a]; }
inline ll invfacll(ll a) { make_fac_cache(a); return invfac_cache[a]; }
inline bool isoutll(ll n, ll r) { return n < 0 || r < 0 || n < r; }
inline ll nPr(ll n, ll r) { return isoutll(n, r) ? 0 : facll(n) * invfacll(n-r) % pdiv; }
inline ll nCr(ll n, ll r) { return isoutll(n, r) ? 0 : facll(n) * invfacll(n-r) % pdiv * invfacll(r) % pdiv; }
inline ll nHr(ll n, ll r) { return nCr(n+r-1, r); }

// 処理内容
int main() {
    
    // インタラクティブ問題では除去した方がいいかも
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n; cin >> n;

    ll coans = 0;
    RANGE(i, n/2+1, n) {
        (coans += nCr(n, i) * powll(2, n-i) % pdiv * 2 % pdiv) %= pdiv;
    }

    ll ans = (powll(3, n) + pdiv - coans) % pdiv;
    cout << ans << endl;
    
}
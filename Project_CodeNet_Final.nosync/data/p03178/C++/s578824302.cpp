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
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

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
constexpr ll pdiv = 1000000007LL;

// 処理内容
int main() {
    
    string k; cin >> k;
    ll d; cin >> d;
    
    const ll n = k.size();
    // dp[i][j][l] := i桁見てj mod dのもので、k未満が確定している(l)ものの数
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(d, vector<ll>(2, 0)));
    dp[0][0][0] = 1;
    REP(i, n) {
        ll g = k[i] - '0';
        REP(j, d) {
            REP(h, 10) {
                // 俗
                (dp[i+1][(j + h) % d][1] += dp[i][j][1]) %= pdiv;
                if (h < g) { // 還俗
                    (dp[i+1][(j + h) % d][1] += dp[i][j][0]) %= pdiv;
                } else if (h == g) { // 精進
                    (dp[i+1][(j + h) % d][0] += dp[i][j][0]) %= pdiv;
                }
            }
        }
    }

    // 0は含まない
    cout << ((dp[n][0][0] + dp[n][0][1]) % pdiv + pdiv - 1) % pdiv << endl;

    
}
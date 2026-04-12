#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int dig, k;
    cin >> s >> k;
    dig = s.size();
    ll dp[102][2][5] = {};
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][1] = (int)(s[0] - '1');
    repp (i, 1, dig) {
        reprev (k, 4) {
            dp[i + 1][0][k]     += (s[i] == '0' ? dp[i][0][k] : 0);
            dp[i + 1][0][k + 1] += (s[i] != '0' ? dp[i][0][k] : 0);
            dp[i + 1][1][k]     += (s[i] != '0' ? dp[i][0][k] : 0);
            dp[i + 1][1][k + 1] += (s[i] != '0' ? dp[i][0][k] * (int)(s[i] - '1') : 0);
            dp[i + 1][1][k]     += dp[i][1][k];
            dp[i + 1][1][k + 1] += dp[i][1][k] * 9;
            
        }
    }
    rep (i, dig + 1) {
        rep (j, 2) {
            rep (k, 5) {
                eprintf("%lld ", dp[i][j][k]);
            }
            eprintf("\n");
        }
        eprintf("\n");
    }
    int ans = 0;
    cout << dp[dig][0][k] + dp[dig][1][k] << "\n";
    return 0;
}
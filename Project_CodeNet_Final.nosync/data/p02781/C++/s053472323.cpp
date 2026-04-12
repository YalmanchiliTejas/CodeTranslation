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

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string n; int k; cin >> n >> k;
    int l = n.size();
    vector<vector<vector<int>>> dp(l + 1, vector<vector<int>>(2, vector<int>(5)));
    dp[0][0][0] = 1;
    rep (i, l) {
        int d = (int)n[i] - '0';
        rep (j, k + 1) {
            dp[i + 1][0][j + (d != 0)] += dp[i][0][j]; 
            dp[i + 1][1][j + 1] += max(0, d - 1) * dp[i][0][j];
            dp[i + 1][1][j] += (d != 0 ? dp[i][0][j] : 0);
            dp[i + 1][1][j + 1] += 9 * dp[i][1][j];
            dp[i + 1][1][j] += dp[i][1][j];
        }
    }
    cout << dp[l][0][k] + dp[l][1][k] << "\n";
    return 0;
}
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
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

vector<int> a;
vector<vector<ll> > dp;
vector<vector<bool> > used;
ll rec (int l, int r) {
    if (l >= r) return 0;
    ll x, y;
    x = a[r - 1] - (used[l][r - 1] ? dp[l][r - 1] : rec(l, r - 1));
    y = a[l] - (used[l + 1][r] ? dp[l + 1][r] : rec(l + 1, r));
    used[l][r] = true;
    return dp[l][r] = max(x, y);
}
int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    a.resize(n); rep (i, n) cin >> a[i];
    dp.resize(n + 1); rep (i, dp.size()) dp[i].resize(dp.size());
    used.resize(n + 1); rep (i, used.size()) used[i].resize(used.size());
    cout << rec(0, n) << "\n";
    return 0;
}
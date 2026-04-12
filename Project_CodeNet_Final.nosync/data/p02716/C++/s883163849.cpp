#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <functional>
#include <cstring>
#include <regex>
#include <random>
#include <cassert>
#include <stack>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define revrepr(i, s, n) for (int i = (n) - 1; i >= s; i--)
#define debug(x) cerr << #x << ": " << x << "\n"
#define popcnt(x) __builtin_popcount(x)

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T>
istream& operator >>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) cin >> v.at(i);
    return is;
}

template<class T, class U>
ostream& operator <<(ostream &os, pair<T, U> p) {
    cout << '(' << p.first << ", " << p.second << ')';
    return os;
}

template<class T>
void print(const vector<T> &v, const string &delimiter) { rep(i, v.size()) cout << (0 < i ? delimiter : "") << v.at(i); cout << endl; }

template<class T>
void print(const vector<vector<T>> &vv, const string &delimiter) { for (const auto &v: vv) print(v, delimiter); }


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(3, -INF));
    dp[0][0] = 0;
    dp[1][2] = a[0];
    dp[1][1] = 0;
    repr(i, 2, n + 1) {
        if (i % 2 == 0) chmax(dp[i][0], max(dp[i - 1][2], dp[i - 2][0] + a[i - 1]));
        else {
            chmax(dp[i][1], max(dp[i - 1][0], dp[i - 2][1] + a[i - 1]));
            chmax(dp[i][2], dp[i - 2][2] + a[i - 1]);
        }
    }
    ll ans = 0;
    if (n % 2 == 0) ans = dp[n][0];
    else ans = dp[n][1];
    cout << ans << endl;
}
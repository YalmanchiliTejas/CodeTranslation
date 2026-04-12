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

int n;
vector<ll> a;
vector<vector<ll>> memo(3001, vector<ll>(3001, -1));

ll solve(int p1, int p2, int t) {
    if (p2 < p1) return 0;
    if (memo[p1][p2] != -1) return memo[p1][p2];
    if (t % 2) {
        ll res = 0;
        chmax(res, a[p1] + solve(p1 + 1, p2, t + 1));
        chmax(res, a[p2] + solve(p1, p2 - 1, t + 1));
        return memo[p1][p2] = res;
    }
    else {
        ll res = 1000000000000000;
        chmin(res, solve(p1 + 1, p2, t + 1));
        chmin(res, solve(p1, p2 - 1, t + 1));
        return memo[p1][p2] = res;
    }
}

int main() {
    cin >> n;
    a.resize(n);
    cin >> a;
    
    ll s = 0;
    rep(i, n) s += a[i];
    cout << 2 * solve(0, n - 1, 1) - s << endl;
}
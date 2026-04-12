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
#include <climits>
#include <chrono>
using namespace std;

#pragma region

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define revrepr(i, s, n) for (int i = (n) - 1; i >= s; i--)
#define debug(x) cerr << #x << ": " << x << "\n"
#define popcnt(x) __builtin_popcount(x)

const double PI = acos(-1.0);

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
void print(const vector<T> &v, const string &delimiter = " ") { rep(i, v.size()) cout << (0 < i ? delimiter : "") << v.at(i); cout << endl; }

template<class T>
void print(const vector<vector<T>> &vv, const string &delimiter) { for (const auto &v: vv) print(v, delimiter); }

#pragma endregion


int main() {
    int x;
    cin >> x;
    cout << (30 <= x ? "Yes" : "No") << endl;
}
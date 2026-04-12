#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, s, n) for (int i = (s); i < (int)(n); i++)

using ll = long long;
using P = pair<int, int>;

const long long MOD = 1e9+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T>
istream& operator>>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) cin >> v.at(i);
    return is;
}

vector<ll> sz(51);
vector<ll> cnt_p(51);
ll solve(int n, ll x) {
    if (x <= 0) return 0;
    if (sz[n] - 1 <= x) return cnt_p[n];

    if (x <= sz[n] / 2) return solve(n - 1, x - 1);
    return cnt_p[n - 1] + 1 + solve(n - 1, x - sz[n - 1] - 2);
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    sz[0] = 1;
    repr(i, 1, n + 1) sz[i] = sz[i - 1] * 2 + 3;
    cnt_p[0] = 1;
    repr(i, 1, n + 1) cnt_p[i] = cnt_p[i - 1] * 2 + 1;
    
    cout << solve(n, x) << endl;
}
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const ll INFL = (1LL << 62);
const ll MOD = 1000000007;
template <class T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
template <class T>
ll mod_pow(ll a, ll n, T mod) {
    mod = (ll)mod;
    ll res = 1, p = a % mod;
    while (n) {
        if (n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];
    int prev_index = -1;
    rep(i, W) {
        if (A[0][i] == '#') {
            prev_index = i;
        } else {
            break;
        }
    }
    if (prev_index == -1) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 1; i < H; i++) {
        int now_index = -1;
        rep(j, prev_index) {
            if (A[i][j] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        for (int j = prev_index; j < W; j++) {
            if (A[i][j] == '#')
                now_index = j;
            else
                break;
        }
        for (int j = now_index + 1; j < W; j++) {
            if (A[i][j] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        if (now_index >= prev_index) {
            prev_index = now_index;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;

    return 0;
}
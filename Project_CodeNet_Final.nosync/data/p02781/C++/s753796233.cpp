#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
using namespace std;
using ll = long long;


unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}
void dfs() {

}

int main() {
    string n;
    ll k;
    cin >> n >> k;
    ll b = n.size();
    vector<vector<ll>> dp(b + 1, vector<ll>(k + 2));
    vector<vector<ll>> same(b + 1, vector<ll>(k + 2));
    same[0][1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j < k+2; j++) {
            if (n[i] == '0') {
                dp[i + 1][j] = dp[i][j] + dp[i][j - 1] * 9;
                same[i + 1][j] = same[i][j];
            }
            else {
                dp[i + 1][j] = dp[i][j] + dp[i][j - 1] * 9 + same[i][j]+same[i][j-1]*((n[i]-'0')-1);
                same[i + 1][j] = same[i][j-1];
            }
        }
    }
    cout << same[b][k+1] + dp[b][k+1] << endl;
}
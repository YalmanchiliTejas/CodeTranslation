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

ll ll_gcd(ll a, ll b) {
    if (a < b) return ll_gcd(b, a);
    ll r;
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

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> z(n);
    for (int i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        z[b].push_back(a);
        z[a].push_back(b);
    }
    vector<ll> hon(n);
    queue<ll> q;
    for (int i = 0; i < n; i++) {
        hon[i] = z[i].size();
        if (hon[i] == 1)q.push(i);
    }
    vector<bool> seen(n, false);
    string ans = "Second";
    while (!q.empty()) {

        if (seen[q.front()] == true) {
            q.pop();
            continue;
        }

        ll now = q.front();
        if (hon[now] == 0) {
            ans = "First";
            break;
        }
        seen[now] = true;

        ll g = -1;
        for (int i = 0; i < z[now].size(); i++) {
            if (seen[z[now][i]] == false) {
                g = z[now][i];
            }
        }
        hon[g] = 0;
        seen[g]=true;
        for (int i = 0; i < z[g].size(); i++) {
            if (seen[z[g][i]] == true)continue;
            if (z[g][i] == now)continue;
            hon[z[g][i]]--;
            if (hon[z[g][i]]==1) {
                q.push(z[g][i]);
            }
            if (hon[z[g][i]] == 0) {
                ans = "First";
                break;
            }
        }
        if (ans == "First")break;
        q.pop();
    }
    cout << ans << endl;
}
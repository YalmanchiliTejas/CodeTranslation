#include <bits/stdc++.h>

using namespace std;
using llong = long long int;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define stl_repr(itr, x) for (auto itr = x.rbegin(); itr != x.rend(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000007;
const static int IINF = INT_MAX;
const static llong LINF = LLONG_MAX;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

/* --------------- template start --------------- */
template <typename T> 
struct BinaryIndexTree { // [1, n]
    vector<T> array;
    int n;

    BinaryIndexTree(int _n) {
        array.resize(_n + 1, 0);
        n = _n;
    }

    T cumsum(int i) {
        T s = 0;
        while(i > 0) {
            s += array[i];
            i -= i & -i;
        }

        return s;
    }

    T sum(int i, int j) {
        T ret_i = cumsum(i - 1);
        T ret_j = cumsum(j);

        return ret_j - ret_i;
    }

    void add(int i, T x) {
        while (i <= n) {
            array[i] += x;
            i += i & -i;
        }
    }
};

template<typename T>
struct UnionFind {
    vector<int> par;
    vector<T> sz;

    UnionFind(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_root(int x) {
        return par[x] == x ? x : par[x] = find_root(par[x]);
    }

    bool same(int x, int y) {
        return find_root(x) == find_root(y);
    }

    void unite(int x, int y) {
        x = find_root(x);
        y = find_root(y);
        if (x == y) return;
        
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }

    T size_of_tree(int x) {
        return sz[find_root(x)];
    }
};
/* --------------- template end --------------- */

/* --------------- function start --------------- */
llong my_gcd(llong a, llong b) {
    return (a ? my_gcd(b % a, a) : b);
}
llong my_lcm(llong a, llong b) {
    return a * b / my_gcd(a, b);    
}

llong facmod(llong n) {
    if (n == 0) return 1;

    llong res = n;
    for (int i = n - 1; i > 0; --i) {
        res = (res * i) % MOD;
    }

    return res;
}
llong powmod(llong a, llong n) {
    llong res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }

    return res;
}
llong modinv(llong n) {
    return powmod(n, MOD - 2);
}
llong combmod(llong n, llong k) {
    llong res = 1;
    for (int i = 0; i < k; ++i) {
        res = (res * (n - i)) % MOD;
    }
    res = (res * modinv(facmod(k))) % MOD;

    return res;
}
/* --------------- function start --------------- */

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}
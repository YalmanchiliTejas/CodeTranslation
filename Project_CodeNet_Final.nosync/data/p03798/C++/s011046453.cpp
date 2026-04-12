#include<iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <queue>
#include <fstream>
#include <functional>

using namespace std;
using ll = long long;

#define all(x) (x).begin(),(x).end()
#define PRI(n) cout << n <<endl;
#define PRI2(n, m) cout << n << " " << m << " "<<endl;

#define REP(i, n)  for(int i = 0; i < (int)n; ++i)
#define REPbit(bit, n)  for(int bit = 0; bit < (int)(1<<n); ++bit)
#define FOR(i, t, n)  for(int i = t; i <= (int)n; ++i)

const char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                           's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const ll MOD = (ll) 1e9 + 7;
const int MAX_INT = 1 << 17;

struct edge {
    int to, cost;
    bool flag = false;
};

bool isPrime(ll x) {
    if (x == 0)return 0;
    if (x == 1)return 0;
    if (x == 2)return 1;
    if (x % 2 == 0)return 0;
    FOR(i, 3, x - 1) {
        if (x % i == 0)return 0;
    }
    return 1;
}

ll GCD(ll a, ll b) {
    if (b == 0)return a;
    return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    ll gcd = GCD(a, b);
    return a / gcd * b;
}

ll nCr(int n, int r) {
    vector<ll> C(r + 1);
    C[0] = 1;
    FOR(i, 1, n) for (int j = min(i, r); j < 1; --j)C[j] = (C[j] + C[j - 1]) % MOD;
    return C[r];
}

template<class T>
class SegTree {
    int n;
    vector<T> data;
    T def;
    function<T(T, T)> operation;
    function<T(T, T)> update;

    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def;
        if (a <= l && r <= b)
            return data[k];
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return operation(c1, c2);
        }
    }

public:
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
            function<T(T, T)> _update)
            : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }

    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    T operator[](int i) {
        return data[i + n - 1];
    }
};

struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int N) {
        for (int i = 0; i < N; ++i) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (par[x] == x)return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (rank[x] < rank[y])par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y])rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<bool> ans(N);

    REP(v, 2) {
        REP(b, 2) {
            ans[0] = v;
            ans[1] = b;
            FOR(i, 2, N - 1) {
                if (s[i - 1] == 'o') {
                    if (ans[i - 1] == 0)ans[i] = ans[i - 2];
                    if (ans[i - 1] == 1)ans[i] = !ans[i - 2];
                }
                if (s[i - 1] == 'x') {
                    if (ans[i - 1] == 0)ans[i] = !ans[i - 2];
                    if (ans[i - 1] == 1)ans[i] = ans[i - 2];
                }
            }
            if (('x' == s[N - 1]) == ans[N - 1] ^ ans[N - 2] ^ ans[0])
                if (('x' == s[0]) == ans[0] ^ ans[N - 1] ^ ans[1]) {
                    REP(i, N)printf("%c", ans[i] == 0 ? 'S' : 'W');
                    cout << endl;
                    return 0;
                }
        }
    }
    cout << -1 << endl;
    return 0;
}

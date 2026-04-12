/*
Author : Xinyuan
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef long long int ll;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

const int nax = 2e5 + 5;
VII intervals[nax];

// add to the prefix
// give the min of everything
struct S {
    ll small, lazy;
    void merge(const S& a, const S& b) {
        small = min(a.small, b.small);
        assert(lazy == 0);
    }
    void add(ll x) {
        small += x;
        lazy += x;
    }
};

vector<S> tree;
const int TYPE_ADD = 1, TYPE_MIN = 2;
void rec(int id, int low, int high, int q_low, int q_high, int type, ll& x) {
    if (high < q_low || q_high < low) {
        return;
    }
    if (q_low <= low && high <= q_high) {
        if (type == TYPE_ADD) {
            tree[id].add(x);
        } else if (type == TYPE_MIN) {
            x = min(x, tree[id].small);
        } else {
            assert(false);
        }
        return;
    }
    for (int b : {2 * id, 2 * id + 1}) {
        tree[b].add(tree[id].lazy);
    }
    tree[id].lazy = 0;
    int last_left = (low + high) / 2;
    rec(2 * id, low, last_left, q_low, q_high, type, x);
    rec(2 * id + 1, last_left + 1, high, q_low, q_high, type, x);
    tree[id].merge(tree[2 * id], tree[2 * id + 1]);
}

int main() {
    int n = nxt(), m = nxt();
    ll sum_of_scores = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        intervals[b].emplace_back(a, c);
        sum_of_scores += c;
    }
    ll answer = 0;
    int base = 1;
    while (base <= n + 1) base *= 2;
    tree.resize(2 * base, {INF, 0});
    ll w = 0 - INF;
    rec(1, 0, base - 1, 0, 0, TYPE_ADD, w);
    for (int i = 1; i <= n + 1; i++) {
        // I want to put '1' here
        for (PII p : intervals[i - 1]) {
            ll whatever = p.second;
            rec(1, 0, base - 1, 0, p.first - 1, TYPE_ADD, whatever);
        }
        ll best = INF;
        rec(1, 0, base - 1, 0, base - 1, TYPE_MIN, best);
        if (i == n + 1) answer = best;
        w = best - INF;
        rec(1, 0, base - 1, i, i, TYPE_ADD, w);
    }
    printf("%lld\n", sum_of_scores - answer);
    return 0;
}

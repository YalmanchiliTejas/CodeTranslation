#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>
#define BUG cout << "acdsfas" << endl
#define int long long

struct seg {
    int l, r, val;
    bool operator < (const seg &b) const {
        return mp(l, r) < mp(b.l, b.r);
    }
};

const int mod = 1e9 + 7;
const ll inf = 2e15;
const int N = 2e5 + 15;
int n, m, dp[N], t[N << 2], add[N << 2];
multiset <pll> cur;
seg a[N];

inline void push(int v) {
    if(v < N + N) {
        t[v << 1] += add[v];
        t[v << 1 | 1] += add[v];
        add[v << 1] += add[v];
        add[v << 1 | 1] += add[v];
        add[v] = 0;
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l)
        return -inf;
    push(v);
    if(tl >= l && tr <= r)
        return t[v];
    int mid = tl + tr >> 1;
    return max(get(v << 1, tl, mid, l, r), get(v << 1 | 1, mid + 1, tr, l, r));
}

void multiupdate(int v, int tl, int tr, int l, int r, int val) {
    if(tl > r || tr < l)
        return;
    push(v);
    if(tl >= l && tr <= r) {
        t[v] += val;
        add[v] += val;
        return;
    }
    int mid = tl + tr >> 1;
    multiupdate(v << 1, tl, mid, l, r, val);
    multiupdate(v << 1 | 1, mid + 1, tr, l, r, val);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

vector <pll> ev[N];

main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].val;
        ev[a[i].l].pb({a[i].l - 1, a[i].val});
        ev[a[i].r + 1].pb({a[i].l - 1, -a[i].val});
    }
    for(int i = 1, j = 1; i <= n; ++i) {
        for(pll x : ev[i])
            multiupdate(1, 0, n, 0, x.f, x.se);
        dp[i] = get(1, 0, n, 0, i - 1);
        multiupdate(1, 0, n, i, i, dp[i]);
    }
    cout << max(0LL, *max_element(dp + 1, dp + 1 + n)) << endl;
    return 0;
}

//#include <cmath>
//#include <ctime>
#include <cstdio>
#include <climits>
//#include <cstdlib>
//#include <cstring>

//#include <map>
//#include <set>
//#include <queue>
//#include <string>
#include <vector>
//#include <sstream>
//#include <iostream>
#include <algorithm>
//#include <functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 200005;
const int P = 1000000007;
const int INF = 1000000007;
const double eps = 1e-6;

inline int getint() {
    int r = 0; bool b = true; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') b = false; c = getchar(); }
    while (c >= '0' && c <= '9') { r = (r<<1)+(r<<3) + c - '0'; c = getchar(); }
    return b ? r : -r;
}

int l[MAXN], r[MAXN];

LL a[MAXN];

vector<int> L[MAXN];
vector<int> R[MAXN];

int root, lc[MAXN * 2], rc[MAXN * 2];
LL mx[MAXN * 2], tag[MAXN * 2], ans, qans;

int n, m, tot;

void build(int &x, int l, int r) {
    x = ++tot;
    mx[x] = tag[x] = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        build(lc[x], l, mid);
        build(rc[x], mid + 1, r);
    }
}


void add(int x, LL val) {
    mx[x] += val;
    tag[x] += val;
}

void push_down(int x) {
    if (tag[x] != 0ll) {
        add(lc[x], tag[x]);
        add(rc[x], tag[x]);
        tag[x] = 0ll;
    }
}

void push_up(int x) {
    mx[x] = max(mx[lc[x]], mx[rc[x]]);
}

void modify(int x, int l, int r, int ll, int rr, LL val) {
    if (ll <= l && r <= rr) {
        add(x, val);
        return;
    }
    push_down(x);
    int mid = (l + r) >> 1;
    if (ll <= mid) modify(lc[x], l, mid, ll, rr, val);
    if (rr > mid) modify(rc[x], mid + 1, r, ll, rr, val);
    push_up(x);
}

void query(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
        qans = max(qans, mx[x]);
        return;
    }
    push_down(x);
    int mid = (l + r) >> 1;
    if (ll <= mid) query(lc[x], l, mid, ll, rr);
    if (rr > mid) query(rc[x], mid + 1, r, ll, rr);
}

int main() {
    n = getint();
    m = getint();
    for (int i = 1; i <= m; ++i) {
        l[i] = getint();
        r[i] = getint();
        a[i] = getint();
        L[l[i]].push_back(i);
        R[r[i]].push_back(i);
    }
    build(root, 0, 200001);
    for (int i = 1; i <= n + 1; ++i) {
        for (auto j : L[i])
            modify(root, 0, 200001, 0, l[j] - 1, a[j]);
        qans = LONG_LONG_MIN;
        query(root, 0, 200001, 0, i - 1);
        ans = max(ans, qans);
        #ifdef DEBUGMODE
        printf("%lld\n", qans);
        #endif
        
        modify(root, 0, 200001, i, i, qans);
        for (auto j : R[i])
            modify(root, 0, 200001, 0, l[j] - 1, -a[j]);
    }

    printf("%lld", ans);
}

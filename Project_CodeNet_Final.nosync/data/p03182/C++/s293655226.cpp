#include "bits/stdc++.h"
#define int long long
using namespace std;

const int TREE_SZ = 1 << 19;

vector<int> mx(TREE_SZ, -2e18);
vector<int> buf(TREE_SZ);

void upd(int v, int l, int r) {
    mx[v] += buf[v];
    if (l < r - 1) {
        buf[2 * v + 1] += buf[v];
        buf[2 * v + 2] += buf[v];
    }
    buf[v] = 0;
}

void add_seg(int v, int l, int r, int L, int R, int x) {
    upd(v, l, r);
    if (r <= L || R <= l) {
        return;
    }
    if (L <= l && r <= R) {
        buf[v] += x;
        upd(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    add_seg(2 * v + 1, l, m, L, R, x);
    add_seg(2 * v + 2, m, r, L, R, x);
    mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
}

void set_elem(int v, int l, int r, int i, int x) {
    upd(v, l, r);
    if (l == r - 1) {
        mx[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        set_elem(2 * v + 1, l, m, i, x);
        upd(2 * v + 2, m, r);
    } else {
        upd(2 * v + 1, l, m);
        set_elem(2 * v + 2, m, r, i, x);
    }
    mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(n, 0);
    vector<vector<pair<int, int>>> r(n + 1);
    for (int i = 0; i < m; i++) {
        int L, R, a;
        cin >> L >> R >> a;
        L--;
        l[L] += a;
        r[R].push_back({L, a});
    }
    int cur_max = 0;
    set_elem(0, -1, n, -1, 0);
    for (int i = 0; i < n; i++) {
        add_seg(0, -1, n, -1, i, l[i]);
        for (auto x: r[i]) {
            add_seg(0, -1, n, -1, x.first, -x.second);
        }
        cur_max = max(cur_max, mx[0]);
        set_elem(0, -1, n, i, mx[0]);
    }
    cout << cur_max << endl;
}

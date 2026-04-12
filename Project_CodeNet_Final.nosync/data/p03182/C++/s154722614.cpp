#include <iostream>
#include <vector>

using namespace std;

struct node {
    int l, r;
    long long x, z;
} tree[800004];

void build(int x, int ql, int qr) {
    tree[x].l = ql;
    tree[x].r = qr;
    tree[x].x = 1ll * 200000 * 1000000000 + 1;
    tree[x].z = 0;
    if (ql != qr) {
        build(2 * x, ql, (ql + qr) / 2);
        build(2 * x + 1, (ql + qr) / 2 + 1, qr);
    }
}

void prop(int x) {
    if (tree[x].l != tree[x].r) {
        tree[2 * x].z += tree[x].z;
        tree[2 * x + 1].z += tree[x].z;
    }
    tree[x].x += tree[x].z;
    tree[x].z = 0;
}

void pull(int x) {
    prop(x);
    prop(2 * x);
    prop(2 * x + 1);
    tree[x].x = min(tree[2 * x].x, tree[2 * x + 1].x);
}

long long query(int x, int ql, int qr) {
    prop(x);
    if (tree[x].l > qr || ql > tree[x].r) return 1ll * 200000 * 1000000000 + 1;
    if (ql <= tree[x].l && tree[x].r <= qr) return tree[x].x;
    return min(query(2 * x, ql, qr), query(2 * x + 1, ql, qr));
}

void upd(int x, int ql, int qr, long long v) {
    prop(x);
    if (tree[x].l > qr || ql > tree[x].r) return;
    if (ql <= tree[x].l && tree[x].r <= qr) {
        tree[x].z += v;
        return;
    }
    upd(2 * x, ql, qr, v);
    upd(2 * x + 1, ql, qr, v);
    pull(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int> > qry[n];
    long long ans = 0;
    while (m--) {
        int l, r, a; cin >> l >> r >> a;
        l--; r--;
        qry[r].push_back(make_pair(l, a));
        ans += a;
    }
    build(1, 0, n);
    upd(1, 0, 0, 0 - query(1, 0, 0));
    for (int i = 0; i < n; i++) {
        upd(1, i + 1, i + 1, query(1, 0, i) - query(1, i + 1, i + 1));
        for (int j = 0; j < qry[i].size(); j++) upd(1, 0, qry[i][j].first, qry[i][j].second);
    }
    cout << ans - query(1, 0, n);
    return 0;
}

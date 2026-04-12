#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
long long f[N], g[N];
vector <pair <int, int> > segment[N];

struct SegmentTree {
    long long node[N << 2], lazy[N << 2];
    void init (int i, int l, int r) {
        if (l == r) {
            node[i] = lazy[i] = 0;
            return;
        }

        int mid = l + r >> 1;
        init(i << 1, l, mid); init(i << 1 | 1, mid + 1, r);
        node[i] = lazy[i] = 0;
    }

    void dolazy (int i, int l, int r) {
        if (lazy[i]) {
            node[i] += lazy[i];
            if (l != r) {
                lazy[i << 1] += lazy[i];
                lazy[i << 1 | 1] += lazy[i];
            }

            lazy[i] = 0;
        }
    }

    void update (int i, int l, int r, int a, int b, long long val) {
        dolazy(i, l, r);
        if (l > r || a > r || b < l) return;
        if (a <= l && r <= b) {
            node[i] += val;
            if (l != r) {
                lazy[i << 1] += val;
                lazy[i << 1 | 1] += val;
            }

            return;
        }

        int mid = l + r >> 1;
        update(i << 1, l, mid, a, b, val); update(i << 1 | 1, mid + 1, r, a, b, val);
        node[i] = max(node[i << 1], node[i << 1 | 1]);
    }

    long long query (int i, int l, int r, int a, int b) {
        if (l > r || a > r || b < l) return -(long long)1e18;
        dolazy(i, l, r);
        if (a <= l && r <= b) return node[i];

        int mid = l + r >> 1;
        return max(query(i << 1, l, mid, a, b), query(i << 1 | 1, mid + 1, r, a, b));
    }
} it;

int main(){
    scanf("%d %d", &n, &m); it.init(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        segment[r].push_back({l, c});
        it.update(1, 1, n, l, r, c);
    }

    for (int i = 1; i <= n; i++) f[i] = it.query(1, 1, n, i, i);
    it.init(1, 1, n);
    for (int i = 1; i <= n; i++) {
        g[i] = max(0LL, it.query(1, 1, n, 1, i));
        it.update(1, 1, n, i, i, g[i]);
        g[i] += f[i];
        for (auto j: segment[i]) it.update(1, 1, n, j.first, i, j.second);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, g[i]);
    printf("%lld", ans);
    return 0;
}

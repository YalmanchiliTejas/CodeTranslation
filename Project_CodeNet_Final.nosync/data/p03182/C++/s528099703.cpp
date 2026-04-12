#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long st[maxn << 2], lz[maxn << 2];
vector<int> Start[maxn];
vector<pair<int, int> > End[maxn];
void down(int id) {
    long long &tmp = lz[id];
    if (tmp == 0) return;
    st[id << 1] += tmp;
    lz[id << 1] += tmp;
    st[id << 1 | 1] += tmp;
    lz[id << 1 | 1] += tmp;
    tmp = 0;
}
void update(int id, int l, int r, int u, int v, long long val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        st[id] += val;
        lz[id] += val;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val); update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}
long long Get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -1e18;
    if (u <= l && r <= v) return st[id];
    down(id);
    int mid = (l + r) >> 1;
    return max(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
}
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int l, r, v;
        cin >> l >> r >> v;
        Start[l].push_back(v);
        End[r].push_back({l, v});
    }
#define update(l, r, x) update(1, 1, n + 1, (l) + 1, (r) + 1, x)
#define Get(x) Get(1, 1, n + 1, 1, (x) + 1)
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int x : Start[i]) 
            update(0, i - 1, x);
        long long cur = Get(i - 1);
        if (cur == 14) cerr << i << endl;
        res = max(res, cur);
        update(i, i, cur);
        for (auto x : End[i]) 
            update(0, x.first - 1, -x.second);
    }
    cout << res;
    return 0;
}
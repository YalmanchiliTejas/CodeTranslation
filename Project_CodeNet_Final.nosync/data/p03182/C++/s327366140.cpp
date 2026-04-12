#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll t[N * 4], lazy[N * 4];

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1e18;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

vector<pair<int, int>> intervals[N];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        intervals[r].push_back({l, a});
    }
    for (int i = 1; i <= n; i++) {
        ll mx = query(1, 1, n, 1, i);
        update(1, 1, n, i, i, mx);
        for (auto q : intervals[i])
            update(1, 1, n, q.first, i, q.second);
    }
    cout << max(0LL, query(1, 1, n, 1, n));
    return 0;
}

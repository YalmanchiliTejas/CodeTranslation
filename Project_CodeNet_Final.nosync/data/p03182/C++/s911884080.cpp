#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct interval {
    int l, r, val;

    bool operator < (const interval& T) const {
        return l < T.l;
    }
}a[200005];

struct dat {
    long long val, lazy;
}tree[800005];

long long dp[200005][2];

int lx, ly;
long long lval;

void push(int ind) {
    if (tree[ind].lazy == 0) return;
    tree[ind * 2].val += tree[ind].lazy;
    tree[ind * 2].lazy += tree[ind].lazy;
    tree[ind * 2 + 1].val += tree[ind].lazy;
    tree[ind * 2 + 1].lazy += tree[ind].lazy;
    tree[ind].lazy = 0;
}

void update(int l, int r, int ind) {
    if (lx <= l && r <= ly) {
        tree[ind].val += lval;
        tree[ind].lazy += lval;
        return;
    }
    push(ind);
    int mid = (l + r) / 2;
   if (lx <= mid) update(l, mid, ind * 2);
   if (ly > mid) update(mid + 1, r, ind * 2 + 1);
   tree[ind].val = max(tree[ind * 2].val, tree[ind * 2 + 1].val);
}

void query(int l, int r, int ind) {
    if (lx <= l && r <= ly) {
        lval = max(lval, tree[ind].val);
        return;
    }
    push(ind);
    int mid = (l + r) / 2;
    if (lx <= mid) query(l, mid, ind * 2);
    if (ly > mid) query(mid + 1, r, ind * 2 + 1);
    tree[ind].val = max(tree[ind * 2].val, tree[ind * 2 + 1].val);
}

void pupdate(int l, int r, int ind) {
    if (l == r) {
        tree[ind].val += lval;
        return;
    }
    push(ind);
    int mid = (l + r) / 2;
    if (lx <= mid) pupdate(l, mid, ind * 2);
    else pupdate(mid + 1, r, ind * 2 + 1);
    tree[ind].val = max(tree[ind * 2].val, tree[ind * 2 + 1].val);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].val);
    }

    sort(a, a + m);

    int p = 0;

    priority_queue <pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

    dp[0][0] = dp[0][1] = 0;
    long long cost = 0;

    for (int i = 1; i <= n; i++) {
        while (p < m && a[p].l <= i) {
            cost += a[p].val;
            pq.push(make_pair(a[p].r, make_pair(a[p].l,  a[p].val)));
            lx = a[p].l;
            ly = a[p].r;
            lval = -a[p].val;
            update(0, n, 1);
            p++;
        }

        while (pq.size() && pq.top().first < i) {
            cost -= pq.top().second.second;
            lx = pq.top().second.first;
            ly = pq.top().first;
            lval = pq.top().second.second;
            update(0, n, 1);
            pq.pop();
        }

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        lx = 0;
        ly = i - 1;
        lval = -INF;
        query(0, n, 1);

        dp[i][1] = lval + cost;

        lx = i;
        lval = dp[i][1];
        pupdate(0, n, 1);

    }

    printf("%lld\n", max(dp[n][0], dp[n][1]));
}

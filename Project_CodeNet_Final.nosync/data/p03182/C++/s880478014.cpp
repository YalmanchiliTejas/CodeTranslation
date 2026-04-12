#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
ll tree[4 * maxn], lazy[4 * maxn];
const ll Inf = 1e18;

void push(int pos, int tl, int tr) {
    if (lazy[pos] != 0){
        tree[pos] += lazy[pos];
        if (tl != tr){
            lazy[2 * pos] += lazy[pos];
            lazy[2 * pos + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
}

void update(int pos, int tl, int tr, int l, int r, ll val) {
    push(pos, tl, tr);
    if(tl > tr or tl > r or tr < l)
        return;
    if(tl >= l && tr <= r) {
        tree[pos] += val;
        if (tl != tr) {
            lazy[pos * 2] += val;
            lazy[2 * pos + 1] += val;
        }
    } else {
        int tm = (tl + tr) / 2;
        update(2 * pos, tl, tm, l, r, val);
        update(2 * pos + 1, tm + 1, tr, l, r, val);
        tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
    }
}

ll query(int pos, int tl, int tr, int l, int r) {
    if(tl > tr || tl > r || tr < l)
        return -Inf;
    push(pos, tl, tr);
    if(tl >= l && tr <= r)
        return tree[pos];
    int tm = (tl + tr) / 2;
    ll leftSubtree = query(2 * pos, tl, tm, l, r);
    ll rightSubtree = query(2 * pos + 1, tm + 1, tr, l, r);
    return max(leftSubtree, rightSubtree);
}


vector<vector<pair<int, int>>> add;
vector<vector<pair<int, int>>> del;

int main()
{
    int n, m;
    cin >> n >> m;
    add.assign(n + 1, vector <pair<int, int>>());
    del.assign(n + 1, vector <pair<int, int>>());
    for (int i = 0; i < m; i++){
        int L, R, a;
        cin >> L >> R >> a;
        add[L].emplace_back(L - 1, a);
        del[R].emplace_back(L - 1, a);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (auto &p : add[i]) {
         int x = p.first, val = p.second;
         update(1, 0, n, 0, x, 1ll * val);
      }

      ll res = query(1, 0, n, 0, i - 1);
      ans = max(res, ans);
        update(1, 0, n, i, i, res);

      for (auto &p : del[i]) {
         int x = p.first, val = p.second;
         update(1, 0, n, 0, x, -1ll * val);
      }
   }
   cout << ans << '\n';
    return 0;
}

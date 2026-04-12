#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300010;
const ll inf = 1e16;

ll f[N];
int n, m;
struct tree { int l, r; ll mx, tag; } t[N << 2];
struct line { int l, r; ll v; } a[N];

#define lc (rt << 1)
#define rc (rt << 1 | 1)
void build(int l, int r, int rt) {
    t[rt].l = l; t[rt].r = r;
    if(l == r) return; int mid = (l + r) >> 1;
    build(l, mid, lc); build(mid + 1, r, rc);
}
void up(int rt) { t[rt].mx = max(t[lc].mx, t[rc].mx); }
#define l (t[rt].l)
#define r (t[rt].r)
#define mid ((l + r) >> 1)
void down(int rt) {
    if(t[rt].tag) {
        t[lc].mx += t[rt].tag; t[rc].mx += t[rt].tag;
        t[lc].tag += t[rt].tag; t[rc].tag += t[rt].tag;
        t[rt].tag = 0;
    }
}
void upd(int L, int R, ll c, int rt) {
    if(L <= l && r <= R) {
        t[rt].mx += c; t[rt].tag += c;
        return;
    }
    down(rt);
    if(L <= mid) upd(L, R, c, lc);
    if(R > mid) upd(L, R, c, rc);
    up(rt);
}
ll query(int L, int R, int rt) {
    if(L <= l && r <= R) return t[rt].mx;
    down(rt); ll ans = -inf;
    if(L <= mid) ans = max(ans, query(L, R, lc));
    if(R > mid) ans = max(ans, query(L, R, rc));
    return ans;
}
#undef l
#undef r
#undef mid
#undef lc
#undef rc

bool operator < (line a, line b) { return a.r < b.r; }

int main() {
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%lld", &a[i].l, &a[i].r, &a[i].v);
    }
    sort(a + 1, a + m + 1);
    int r = 1;
    for(int i = 1; i <= n; ++i) { 
        upd(i, i, query(1, i, 1), 1);
        while(a[r].r == i) {
            upd(a[r].l, a[r].r, a[r].v, 1);
            ++r;
        }
    }
    printf("%lld\n", max(0LL, query(1, n, 1)));
}
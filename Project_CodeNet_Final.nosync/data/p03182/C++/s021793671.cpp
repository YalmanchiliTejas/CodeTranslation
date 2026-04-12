#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
#define ls(x) x << 1
#define rs(x) x << 1 | 1
#define rep(i, a, b) for(int i = a; i <= (int)b; i++)
void read(int &x) {
    x = 0; int flag = 1; char ch = ' ';
    while(ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
void read(ll &x) {
    x = 0; int flag = 1; char ch = ' ';
    while(ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
using namespace std;
const int maxn = 200010;
int n, m;
ll ans[maxn << 2], tag[maxn << 2];
struct Data {
    int l, r, val;
    bool operator < (const Data & a) const { return r < a.r; }
} a[maxn];
void push_up(int p) { ans[p] = max(ans[ls(p)], ans[rs(p)]); }
void change(int p, int l, int r, ll x) {
    tag[p] += x;
    ans[p] += x;
}
void push_down(int p, int l, int r) {
    int mid = (l + r) >> 1;
    change(ls(p), l, mid, tag[p]);
    change(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}
void update(int p, int l, int r, int ql, int qr, ll x) {
    if(ql <= l && r <= qr) {
        change(p, l, r, x);
        return;
    }
    if(tag[p]) push_down(p, l, r);
    int mid = (l + r) >> 1;
    if(ql <= mid) update(ls(p), l, mid, ql, qr, x);
    if(qr > mid) update(rs(p), mid + 1, r, ql, qr, x);
    push_up(p);
}
ll query(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return ans[p];
    if(tag[p]) push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll ret = 0;
    if(ql <= mid) ret = max(ret, query(ls(p), l, mid, ql, qr));
    if(qr > mid) ret = max(ret, query(rs(p), mid + 1, r, ql, qr));
    return ret;
}
int main()
{
    read(n), read(m);
    rep(i, 1, m) {
        read(a[i].l), read(a[i].r), read(a[i].val);
    }
    sort(a + 1, a + 1 + m);
    int cur = 1;
    rep(i, 1, n) {
        update(1, 1, n, i, i, query(1, 1, n, 1, i));
        while(a[cur].r == i) update(1, 1, n, a[cur].l, a[cur].r, a[cur].val), cur++;
    }
    printf("%lld\n", max(ans[1], 0ll));
    return 0;
}
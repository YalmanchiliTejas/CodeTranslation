#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b;  a <= c; ++a)
#define pb push_back
#define int long long
typedef pair<int, int> ii;
const int N = 2e5 + 10;
const int oo = 1e16;

int n, m;
int f[N], it[4 * N], la[4 * N], L[N], R[N], C[N];
vector<ii> vi[N];
struct line {
    int l, r, v;
} t[N];

void true_val(int i, int l, int r)  {
    if(!la[i]) return;
    it[i] += la[i];
    if(l != r)  {
        la[2 * i] += la[i];
        la[2*i + 1] += la[i];
    }
    la[i] = 0;
}
void upd(int i, int l, int r, int ql, int qr, int val, int ti)   {
    true_val(i, l, r);
    if(l > qr || ql > r) return;
    if(ql <= l && r <= qr)  {
        if(ti == 0) {
            la[i] += val; true_val(i, l, r);
        } else {
            it[i] = val;
        }
        return;
    }
    int mid = (l + r) / 2;
    upd(2*i, l, mid, ql, qr, val, ti); upd(2*i + 1, mid + 1, r, ql, qr, val, ti);
    it[i] = max(it[2*i], it[2*i + 1]);
}
int get(int i, int l, int r, int ql, int qr)    {
    true_val(i, l, r);
    if(ql > r || l > qr) return -oo;
    if(ql <= l && r <= qr) return it[i];
    int mid = (l + r) / 2;
    return max(get(2*i, l, mid, ql, qr), get(2*i + 1, mid + 1, r, ql, qr));
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    FOR(i, 0, 4 * n) it[i] = -oo;
    upd(1, 0, n, 0, 0, 0, 1);
    FOR(i, 1, m)    {
        scanf("%lld%lld%lld", &L[i], &R[i], &C[i]);
        vi[L[i]].pb(ii(i, 0)); vi[R[i] + 1].pb(ii(i, 1));
    }
    int ans = 0;
    FOR(i, 1, n)    {
        for(auto v: vi[i])  {
            if(v.se == 0) upd(1, 0, n, 0, i - 1, C[v.fi], 0);
            else upd(1, 0, n, 0, L[v.fi] - 1, -C[v.fi], 0);
        }
        int val = get(1, 0, n, 0, i - 1);
        ans = max(ans, val);
        upd(1, 0, n, i, i, val, 1);
    }
    printf("%lld", ans);
}

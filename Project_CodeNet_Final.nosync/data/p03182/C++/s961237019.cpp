// Date: 2020-03-17

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)x.size())
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

#define mid ((l+r)>>1)
#define lc rt << 1
#define rc rt << 1 | 1
#define lson lc, l, mid
#define rson rc, mid + 1, r

int n, m;
LL mx[N<<2], add[N<<2], sum[N];

void pd(int rt) {
    if(add[rt]) {
        add[lc] += add[rt], mx[lc] += add[rt];
        add[rc] += add[rt], mx[rc] += add[rt];
        add[rt] = 0;
    }
}

void pushup(int rt) {
    mx[rt] = max(mx[lc], mx[rc]);
}

void update(int rt, int l, int r, int ql, int qr, LL v) {
    if(ql <= l && r <= qr) {
        mx[rt] += v;
        add[rt] += v;
        return;
    }
    pd(rt);
    if(ql <= mid) update(lson, ql, qr, v);
    if(qr > mid) update(rson, ql, qr, v);
    pushup(rt);
}

LL ask(int rt, int l, int r, int x) {
    if(l == r) return mx[rt];
    pd(rt);
    if(x <= mid) return ask(lson, x);
    else return max(mx[lc], ask(rson, x));
}

struct seg {
    int l, r, v;
    bool operator < (const seg& rhs) const {
        if(r != rhs.r) return r < rhs.r;
        return l < rhs.l;
    }
} s[N];

LL dp[N];
int main() {
    FIO;
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> s[i].l >> s[i].r >> s[i].v;
        sum[s[i].r] += s[i].v;
    }
    sort(s+1, s+1+m);
    int cur = 1;
    rep(i, 1, n) {
        update(1, 1, n, i, i, ask(1, 1, n, i));
        while(s[cur].r == i) {
            update(1, 1, n, s[cur].l, s[cur].r, s[cur].v);
            cur++;
        }
    }
    LL ans = max(0LL, mx[1]);
    cout << ans;

    return 0;
}
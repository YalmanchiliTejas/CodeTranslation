// Date: 2020-04-07

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define IO freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout)
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define D(x) cout << #x << " = " << x << endl;
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

int n, p[N];
pii a[N], b[N];

struct edge {
    int u, v, w;
    bool operator < (const edge& r) const { return w < r.w; }
} E[N];

int Find(int x) {
    return x == p[x] ? x : p[x] = Find(p[x]);
}

int main() {
    FIO;
    cin >> n;
    rep(i, 1, n) {
        p[i] = i;
        int u, v;
        cin >> u >> v;
        a[i] = mk(u, i);
        b[i] = mk(v, i);
    }
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    int tot = 0;
    rep(i, 2, n) E[++tot] = {a[i].se, a[i-1].se, a[i].fi-a[i-1].fi}, E[++tot] = {b[i].se, b[i-1].se, b[i].fi-b[i-1].fi};
    sort(E+1, E+1+tot);
    LL ans = 0;
    rep(i, 1, tot) {
        int u = E[i].u, v = E[i].v;
        int fu = Find(u), fv = Find(v);
        if(fu != fv) p[fu] = fv, ans += E[i].w;
    }
    cout << ans;

    return 0;
}
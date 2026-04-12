#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define WHATIS(x) cout << #x << " is " << x << endl;
#define ERROR(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x

using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

const ll MODBASE = 1000000007LL;
const int MAXN = 200010;
const int MAXM = 1000010;
const int MAXK = 110;
const int MAXQ = 200010;

int n, m;
ll Max[8*MAXN], lazy[8*MAXN];
vector<II> a[MAXN], b[MAXN];

void lazyupd(int k, int l, int r) {
    if (lazy[k] == 0) return;
    Max[k] += lazy[k];
    if (l < r) {
        lazy[k*2] += lazy[k];
        lazy[k*2+1] += lazy[k];
    }
    lazy[k] = 0;
}

void update(int k, int l, int r, int u, int v, ll gt) {
    lazyupd(k, l, r);
    if (r < u || v < l || l > r) return;
    if (u <= l && r <= v) {
        lazy[k] = gt;
        lazyupd(k, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(k*2, l, m, u, v, gt);
    update(k*2+1, m+1, r, u, v, gt);
    Max[k] = max(Max[k*2], Max[k*2+1]);
}

ll get(int k, int l, int r, int u, int v) {
    lazyupd(k, l, r);
    if (r < u || v < l || l > r) return -1e18;
    if (u <= l && r <= v) return Max[k];
    int m = (l + r) >> 1;
    return max(get(k*2, l, m, u, v), get(k*2+1, m+1, r, u, v));
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    FOR(i,1,m) {
        int u, v, c;
        cin >> u >> v >> c;
        a[v].emplace_back(II(u, c));
        b[u].emplace_back(II(v, c));
    }
    ll res = 0;
    FOR(i,1,n) {
        FOR(j,0,SZ(b[i])-1) {
            int c = b[i][j].SE;
            update(1,0,n,0,i-1,c);
        }

        FOR(j,0,SZ(a[i-1])-1) {
            int u = a[i-1][j].FI;
            int c = a[i-1][j].SE;
            update(1,0,n,0,u-1,-c);
        }

        ll kq = get(1,0,n,0,i-1);
        res = max(res, kq);
        update(1,0,n,i,i,kq);
    }
    cout << res;
    return 0;
}

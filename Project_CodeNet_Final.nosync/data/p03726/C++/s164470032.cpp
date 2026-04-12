#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

struct HopcroftKarp {
    static const int MAXV = 1e5 + 5;
    static const int MAXE = 1e6 + 5;
    int nx, ny, E, adj[MAXE], nxt[MAXE], lst[MAXV], cur[MAXV], lev[MAXV], que[MAXV], matx[MAXV], maty[MAXV];
    void init(int nx, int ny) {
        this->nx = nx, this->ny = ny;
        E = 0, fill_n(lst, nx + 1, -1);
        fill_n(matx, nx + 1, -1), fill_n(maty, ny + 1, -1);
    }
    void add(int x, int y) {
        adj[E] = y, nxt[E] = lst[x], lst[x] = E++;
    }
    int bfs() {
        int qsize = 0;
        for (int x = 1; x <= nx; x++) if (matx[x] != -1) lev[x] = -1;
        else {
            lev[x] = 0;
            que[qsize++] = x;
        }
        int found = 0;
        for (int i = 0; i < qsize; i++) {
            for (int x = que[i], e = lst[x]; e != -1; e = nxt[e]) {
                int y = adj[e];
                if (maty[y] == -1) found = 1;
                else if (lev[maty[y]] == -1) {
                    lev[maty[y]] = lev[x] + 1;
                    que[qsize++] = maty[y];
                }
            }
        }
        return found;
    }
    int dfs(int x) {
        for (int &e = cur[x]; e != -1; e = nxt[e]) {
            int y = adj[e];
            if (maty[y] == -1 || (lev[maty[y]] == lev[x] + 1 && dfs(maty[y]))) {
                matx[x] = y;
                maty[y] = x;
                return 1;
            }
        }
        return 0;
    }
    int maxmat() {
        int res = 0;
        while (bfs()) {
            for (int x = 1; x <= nx; x++) cur[x] = lst[x];
            for (int x = 1; x <= nx; x++) if (matx[x] == -1) res += dfs(x);
        }
        return res;
    }
} hopkarp;

void solve() {
    int n; cin >> n;
    hopkarp.init(n, n);
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        hopkarp.add(u, v);
        hopkarp.add(v, u);
    }
    if (hopkarp.maxmat() == n) {
        cout << "Second\n";
    }
    else {
        cout << "First\n";
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define ins insert
#define f first
#define s second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define files(name) fin(name".in"); fout(name".out")
#define endl "\n"
#define fi(st,n) for (int i = (st); i <= (int)(n); ++i)
#define fj(st,n) for (int j = (st); j <= (int)(n); ++j)
#define fk(st,n) for (int k = (st); k <= (int)(n); ++k)
#define fq(st,n) for (int q = (st); q <= (int)(n); ++q)
#define fw(st,n) for (int w = (st); w <= (int)(n); ++w)
#define ff(i, st, n) for (int (i) = (st); (i) <= (int)(n); ++(i))
#define ei(st,n) for (int i = (st); i >= (int)(n); --i)
#define ej(st,n) for (int j = (st); j >= (int)(n); --j)
#define ek(st,n) for (int k = (st); k >= (int)(n); --k)
#define ef(i, st, n) for (int (i) = (st); (i) >= (int)(n); --(i))
#define ri(st,n) for (int i = (st); i < (int)(n); ++i)
#define rj(st,n) for (int j = (st); j < (int)(n); ++j)
#define rk(st,n) for (int k = (st); k < (int)(n); ++k)
#define rq(st,n) for (int q = (st); q < (int)(n); ++q)
#define rf(i, st, n) for (int (i) = (st); (i) < (int)(n); ++(i))
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define y1 dsklmlvmd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const dbl eps = (dbl) 1e-8;
const int mod = (int) 1e9 + 7;
const int maxn = (int) 1e5 + 5;
//const dbl M_PI = (dbl)2 * (dbl)acos(0);

//cout<<fixed<<setprecision(10);
//srand(time(0));

vector <int>  a[maxn], d[maxn], b[maxn], t[maxn];
int n, ans;

void dfs(int v, int p, int c) {
    if (t[v][p] & c)
        return;
    t[v][p] |= c;

//    cout << v << " " << p << " " << c << endl;

    int toc = c % 2 + 1;
    ri(1, a[v].size()) {
        if (i == p)
            continue;
        int to = a[v][i];
//        cout << "b = " << b[v][i] << endl;
        dfs(to, b[v][i], c % 2 + 1);
    }


    if (c == 1) {
        int kb = 0;
        ri(1, a[v].size()) {
            if (i == p)
                continue;
            int to = a[v][i];
            if (d[to][b[v][i]] & 2)
                ++kb;
        }
        if (kb >= 2) {
            ans = 1;
            return;
        }
        if (kb >= 1) {
            d[v][p] |= 1;
            return;
        }
    }
    if (c == 2) {
        d[v][p] |= 2;
        ri(1, a[v].size()) {
            if (i == p)
                continue;
            int to = a[v][i];
            if (!(d[to][b[v][i]] & 1)) {
                d[v][p] ^= 2;
                break;
            }
        }
    }

}

int main() {
//    fin("t.in");
    sync;
    cin >> n;
    fi(1, n) {
        a[i].pb(0);
        b[i].pb(0);
    }

    fi(1, n - 1) {
        int u, v;
        cin >> u >> v;

        b[v].pb((int)a[u].size());
        b[u].pb((int)a[v].size());
//        cout << a[u].size() << " " << a[v].size() << endl;

        a[v].pb(u);
        a[u].pb(v);
    }
    fi(1, n) {
        fj(1, (int)a[i].size()) {
            d[i].pb(0);
            t[i].pb(0);
        }
    }
    if (n == 2) {
        cout << "Second" << endl;
        return 0;
    }
    ans = 0;

//    dfs(2, 0, 1);
    
    fi(1, n) {
        dfs(i, 0, 1);
    }
    

    if (ans)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
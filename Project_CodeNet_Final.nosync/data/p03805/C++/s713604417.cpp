#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define pb push_back
#define sz(v) ((li)(v).size())
#define bgn(v) ((v).begin())
#define eend(v) ((v).end())
#define allof(v) (v).begin(), (v).end()
#define dodp(v, n) memset(v, (li)n, sizeof(v))
#define bit(n) (1ll << (li)(n))
#define mp(a, b) make_pair(a, b)
#define rin rep(i, n)
#define EPS 1e-12
#define ETOL 1e-8
#define MOD 998244353
typedef pair<li, li> PI;

#define INF bit(60)

#define DBGP 1

#define idp if (DBGP)
#define F first
#define S second
#define p2(a, b) idp cout << a << "\t" << b << endl
#define p3(a, b, c) idp cout << a << "\t" << b << "\t" << c << endl
#define p4(a, b, c, d) idp cout << a << "\t" << b << "\t" << c << "\t" << d << endl
#define p5(a, b, c, d, e) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl
#define p6(a, b, c, d, e, f) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << endl
#define p7(a, b, c, d, e, f, g) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << endl
#define p8(a, b, c, d, e, f, g, h) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << endl
#define p9(a, b, c, d, e, f, g, h, i) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << endl
#define p10(a, b, c, d, e, f, g, h, i, j) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << endl
#define foreach(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define p2p(x) idp p2((x).F, (x).S)
#define dump(x, n)                         \
    idp                                    \
    {                                      \
        rep(i, n) { cout << x[i] << " "; } \
        puts("");                          \
    }
#define dump2(x, n)                                                     \
    idp                                                                 \
    {                                                                   \
        rep(i, n) { cout << "[" << x[i].F << " , " << x[i].S << "] "; } \
        puts("");                                                       \
    }
#define dumpi(x)                  \
    idp                           \
    {                             \
        foreach (it, x)           \
        {                         \
            cout << (*it) << " "; \
        }                         \
        puts("");                 \
    }
#define dumpi2(x)                                               \
    idp                                                         \
    {                                                           \
        foreach (it, x)                                         \
        {                                                       \
            cout << "[" << (it)->F << " , " << (it)->S << "] "; \
        }                                                       \
        puts("");                                               \
    }

#define read2d(a, w, h) rep(i, h) rep(j, w) cin >> a[i][j]
#define dump2d(a, w, h)                   \
    rep(i, h)                             \
    {                                     \
        rep(j, w) cout << a[i][j] << " "; \
        puts("");                         \
    }

typedef pair<li, li> PI;

li n, m;



int main(void)
{
    cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    rep(i, m) {
        li a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    vector<li> v;
    rin{
        v.pb(i);
    }

    li res = 0;
    do {
        bool ok = true;
        if (v[0] != 0) {
            continue;
        }
        rep(i, n - 1) {
            if (!adj[v[i]][v[i + 1]]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            res++;
        }
    } while (next_permutation(allof(v)));
    cout << res << endl;

    return 0;
}
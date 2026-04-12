#include <bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

#define V vector
#define P pair

using LL = long long;
#define FOR(i, x, y) \
    for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
    for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifndef ONLINE_JUDGE
#define dbg(x...)                             \
    do {                                      \
        cerr << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() { cerr << "\033[39;0m" << endl; }
template <template <typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) {
    for (auto v : a) cerr << v << ' ';
    err(x...);
}
template <typename T, typename... A>
void err(T a, A... x) {
    cerr << a << ' ';
    err(x...);
}
#else
#define dbg(...)
#endif
#define sz(x) (int)x.size()

LL bin(LL a, LL b, LL p) {
    LL res = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) res = res * a % p;

    return res;
}

const int N = 1105+50;

namespace dinic {
struct E {
    int to;
    LL cp;
    int label;
    E(int to = 0, LL cp = 0, int label=-1) : to(to), cp(cp), label(label) {}
};
struct Dinic {
    static const int INF = 0x7fffffff;
    static const int N = 1200;
    static const int M = 600 * 600 * 2;
    int m, s, t, n;

    E edges[M];
    int ecnt;
    vector<int> G[N];

    int d[N], cur[N];

    void init(int n, int s, int t) {
        this->s = s;
        this->t = t;
        this->n = n;
        ecnt = m = 0;
        for (int i = 0; i <= n; ++i) G[i].clear();
    }

    void addedge(int u, int v, LL cap, int label=-1) {
        assert(ecnt+2 <= M);
        edges[ecnt++] = E(v, cap, label);
        edges[ecnt++] = E(u, 0);
        G[u].push_back(m++);
        G[v].push_back(m++);
    }

    bool bfs() {
        memset(d, 0, sizeof(int) * (n + 2));
        queue<int> Q;
        Q.push(s);
        d[s] = 1;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int &i : G[x]) {
                E &e = edges[i];
                if (!d[e.to] && e.cp > 0) {
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return d[t];
    }

    LL DFS(int u, LL cp) {
        if (u == t || !cp) return cp;
        LL tmp = cp;
        LL f;
        for (int &i = cur[u]; i < (int)G[u].size(); ++i) {
            E &e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to]) {
                f = DFS(e.to, min(cp, e.cp));
                e.cp -= f;
                edges[G[u][i] ^ 1].cp += f;
                cp -= f;
                if (!cp) break;
            }
        }
        return tmp - cp;
    }

    LL go(int S = -1, int T = -1) {
        if ((~S) && (~T)) {
            s = S;
            t = T;
        }
        LL flow = 0;
        while (bfs()) {
            memset(cur, 0, sizeof(int) * (n + 1));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

class extdinic1
{
public:
    dinic::Dinic dc;
    int S, T;
    LL tf[N];
    LL sum;
    int n;
    void addedge(int u, int v, int lb, int ub, int label=-1) {
        dbg(u, v, lb, ub, label);
        if (lb > ub)
            return;
        tf[v] += lb;
        tf[u] -= lb;

        if (ub > lb)
            dc.addedge(u, v, ub - lb, label);
    }

    void init(int _n) {
        n = _n;
        S = ++n; T = ++n;
        dc.init(n, S, T);
        memset(tf, 0, sizeof(LL) * (n+1));
    }

    LL go()
    {
        sum = 0;
        dbg(n);
        for (int i=1; i<=n-2; ++i)
        {
            if (tf[i] < 0)
            {
                dc.addedge(i, T, -tf[i]);
            }
            else if (tf[i] > 0)
            {
                dc.addedge(S, i, tf[i]);
                sum += tf[i];
            }
        }
        LL ans = dc.go();
        dbg(ans, sum);
        if (ans != sum) return -1;
        else return ans;
    }
};

class extdinic2 : public extdinic1 {
   public:
    static const LL INF = 1e18;
    int s, t;

    void init(int n, int s, int t) {
        this->s = s;
        this->t = t;
        extdinic1::init(n);
    }

    LL go() {
        dc.addedge(t, s, INF);
        LL ans = extdinic1::go();
        if (ans == -1) return -1;
        return 1;
        ans = dc.go(s, t);
        return ans;
    }
};
}  // namespace dinic

typedef unsigned long long ULL;

const int M = 600 * 600;
int s[N], t[N];
ULL a[N], b[N];


int Ans[64][N][N];
int n;

dinic::extdinic2 dc;

bool go(int bit) {
    dbg(bit);
    static int u[N], v[N];
    for (int i=1; i<=n; ++i) {
        u[i] = (a[i] >> bit) & 1;
        v[i] = (b[i] >> bit) & 1;
        dbg(i, s[i], u[i], t[i], v[i]);
    }
    static int ecnt, fr[M], to[M], lb[M], ub[M];
    int S = 2*n+1, T = S+1;
    ecnt = 0;
    for (int i=1; i<=n; ++i) {
        fr[ecnt] = S;
        to[ecnt] = i;
        int low, up;
        if (!s[i]) {
            if (u[i]) {
                low = up = n;
            } else {
                low = 0;
                up = n-1;
            }
        } else {
            if (u[i]) {
                low = 1;
                up = n;
            } else {
                low = up = 0;
            }
        }

        if (low <= up && up > 0) {
            lb[ecnt] = low;
            ub[ecnt++] = up;
        }

        fr[ecnt] = i+n;
        to[ecnt] = T;

        if (!t[i]) {
            if (v[i]) {
                low = up = n;
            } else {
                low = 0;
                up = n-1;
            }
        } else {
            if (v[i]) {
                low = 1;
                up = n;
            } else {
                low = up = 0;
            }
        }
        if (low <= up && up > 0) {
            lb[ecnt] = low;
            ub[ecnt++] = up;
        }

        for (int j=1; j<=n; ++j) {
            fr[ecnt] = i;
            to[ecnt] = j+n;
            lb[ecnt] = 0;
            ub[ecnt++] = 1;
        }
    }
    dc.init(T, S, T);
    dbg(ecnt);
    for (int i=0; i<ecnt; ++i) {
        int label = -1;
        if (fr[i] >= 1 && fr[i] <= n && to[i] >= n+1 && to[i] <= n+n)
            label = (fr[i]-1) * n + to[i]-n-1;
        // printf("%d %d %d %d\n", fr[i], to[i], lb[i], ub[i]);
        dc.addedge(fr[i], to[i], lb[i], ub[i], label);
        
    }
    LL ans = dc.go();
    
    if (~ans) {
        for (int i=0; i<dc.dc.ecnt; ++i) {
            const auto &e = dc.dc.edges[i];
            if (~e.label) {
                int i = e.label / n + 1, j = e.label % n + 1;
                if (e.cp == 0)
                    Ans[bit][i][j] = 1;
            }
        }
        return true;
    } else {
        return false;
    }
    return true;
}

void solve() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &s[i]);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
    }
    for (int i=1; i<=n; ++i) {
        scanf("%llu", &a[i]);
    }
    for (int i=1; i<=n; ++i) {
        scanf("%llu", &b[i]);
    }
    bool suc = true;
    // return;
    for (int i=0; i<64; ++i) {
        suc = suc && go(i);
        if (!suc) {
            puts("-1");
            return;
        }
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            ULL x = 0;
            for (int k = 64-1;k >= 0; --k) {
                x = x << 1 | Ans[k][i][j];
            }
            printf("%llu%c", x, j==n? '\n':' ');
        }
    }
}

int main() {

    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();

    return 0;
}
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const int MOD = 1000000007;
inline int add(int x, int y) { int r = x + y; if(r >= MOD) r -= MOD; return r; }
inline int mul(int x, int y) { return (ll)x * (ll)y % MOD; }

const int MAXN = 100010;
const int MAXM = 200010;

vector<int> G[MAXN], GW[MAXN], T[MAXN], TR[MAXN], TD[MAXN];
int N, M, PS, PT;

namespace dij {
    struct item {
        int u; ll d;
        inline bool operator<(item rhs) const { return d > rhs.d; }
    } A[MAXN];
    priority_queue<item> Q;
    ll dist[MAXN];
    bool done[MAXN];
    inline void work() {
        int i, u, v;
        memset(dist, 0x3f, sizeof(dist));
        dist[PS] = 0, Q.push( (item){ PS, 0 } );
        while(!Q.empty()) {
            u = Q.top().u; Q.pop();

            if(done[u]) continue;
            done[u] = 1;

            for(i = 0; i < G[u].size(); i++) {
                v = G[u][i];
                if(dist[u] + GW[u][i] < dist[v]) {
                    dist[v] = dist[u] + GW[u][i];
                    Q.push( (item){v, dist[v]} );
                }
            }
        }

        for(u = 1; u <= N; u++) for(i = 0; i < G[u].size(); i++) {
            v = G[u][i];
            if(dist[u] + GW[u][i] == dist[v]) {
                T[u].push_back(v), TD[u].push_back( GW[u][i] );
                TR[v].push_back(u);
            }
        }
    }
}

int fromS[MAXN], toT[MAXN];
void getFrom(int u) {
    int i, v;
    fromS[u] = 0;
    for(i = 0; i < TR[u].size(); i++) {
        v = TR[u][i];
        if(fromS[v] == -1) getFrom(v);
        fromS[u] = add(fromS[u], fromS[v]);
    }
}
void getTo(int u) {
    int i, v;
    toT[u] = 0;
    for(i = 0; i < T[u].size(); i++) {
        v = T[u][i];
        if(toT[v] == -1) getTo(v);
        toT[u] = add(toT[u], toT[v]);
    }
}

int main() {
    int i, u, v, d;
    scanf("%d%d%d%d", &N, &M, &PS, &PT);
    for(i = 1; i <= M; i++) {
        scanf("%d%d%d", &u, &v, &d);
        G[u].push_back(v), GW[u].push_back(d);
        G[v].push_back(u), GW[v].push_back(d);
    }

    dij::work();

    memset(fromS, -1, sizeof(fromS)), memset(toT, -1, sizeof(toT));
    fromS[PS] = 1, toT[PT] = 1;
    for(u = 1; u <= N; u++) {
        if(fromS[u] == -1) getFrom(u);
        if(toT[u] == -1) getTo(u);
    }

    int Ans = mul(fromS[PT], fromS[PT]);
    ll totd = dij::dist[PT];
    //dec points
    for(u = 1; u <= N; u++) if(dij::dist[u] == totd - dij::dist[u]) {
        Ans = add(Ans, MOD - mul( mul(fromS[u], toT[u]) , mul(fromS[u], toT[u]) ));
    }
    //dec sides
    for(u = 1; u <= N; u++) for(i = 0; i < T[u].size(); i++) {
        v = T[u][i];

        ll T1 = dij::dist[u], T2 = totd - dij::dist[v], x = T2 - T1 + TD[u][i];
        if(x > 0 && x < 2 * TD[u][i]) Ans = add(Ans, MOD - mul( mul(fromS[u], toT[v]), mul(fromS[u], toT[v]) ) );
    }

    printf("%d", Ans);
}

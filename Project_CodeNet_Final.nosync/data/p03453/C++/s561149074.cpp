#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
#define P 1000000007

#define M 400010
#define in(A, B, C) ((A) >= (B) && (A) <= (C))

using namespace std;

typedef long long ll;

int n, m, S, T, Head[M], Next[M], Go[M], Val[M], Can[M], Cnt = 1;

bool vis[M], used[M];

ll Dis[M], F[M], G[M], totdis;

struct node {
    ll dis, w;
    node(){}
    node(ll _1, ll _2) {
        dis = _1;
        w = _2;
    }
    bool operator < (const node& X) const {
        return dis > X.dis;
    }
};

priority_queue <node> Q;

void addedge(int x, int y, int z) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Val[Cnt] = z;
    Head[x] = Cnt;
}

void DIJ() {
    Q.push(node(0, S));
    for(int i = 1; i <= n; i++) Dis[i] = 1e18;
    Dis[S] = 0;
    for(; ;) {
        while(!Q.empty() && vis[Q.top().w]) Q.pop();
        if(Q.empty()) break;
        int W = Q.top().w;
        Q.pop();
        vis[W] = 1; //!!!
        for(int T = Head[W]; T; T = Next[T])
            if(Dis[Go[T]] > Dis[W] + Val[T]) {
                Dis[Go[T]] = Dis[W] + Val[T];
                Q.push(node(Dis[Go[T]], Go[T]));
            }
    }
    totdis = Dis[T];
    for(int i = 1; i <= n; i++)
        for(int T = Head[i]; T; T = Next[T])
            if(Dis[Go[T]] == Dis[i] + Val[T]) {
                Can[T] = 1;
                if(in(totdis - Dis[i], Dis[i] + 1, Dis[Go[T]]) || in(totdis - Dis[Go[T]], Dis[i], Dis[Go[T]] - 1))
                    Can[T] = 2;
            }
}

void add(ll &x, ll y) {
    x = (x + y) % P;
}

void calcS(int x) {
    if(used[x]) return;
    used[x] = 1;
    for(int T = Head[x]; T; T = Next[T]) if(Can[T]) calcS(Go[T]);
    for(int T = Head[x]; T; T = Next[T]) if(Can[T])
        add(F[x], F[Go[T]]);
        
}

void calcT(int x) {
    if(used[x]) return;
    used[x] = 1;
    for(int T = Head[x]; T; T = Next[T]) if(Can[T ^ 1]) calcT(Go[T]);
    for(int T = Head[x]; T; T = Next[T]) if(Can[T ^ 1])
        add(G[x], G[Go[T]]);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    DIJ();
    F[T] = 1;
    used[T] = 1;
    calcS(S);
    memset(used, 0, sizeof used);
    used[S] = 1;
    G[S] = 1;
    calcT(T);
    ll ans = F[S] * F[S] % P;
    for(int i = 1; i <= n; i++)
        for(int T = Head[i]; T; T = Next[T])
            if(Can[T] == 2)
                add(ans, -G[i] * F[Go[T]] % P * G[i] % P * F[Go[T]] % P);
    for(int i = 1; i <= n; i++) if(Dis[i] == totdis / 2)
        add(ans, -F[i] * G[i] % P * F[i] % P * G[i] % P);
    printf("%lld\n", (ans % P + P) % P);
    return 0;
}
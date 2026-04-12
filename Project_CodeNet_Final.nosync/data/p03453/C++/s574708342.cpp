#include <bits/stdc++.h>
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define For(i, l, r) for(int i = (l); i <= (int)(r); ++i)
#define Fordown(i, r, l) for(int i = (r); i >= (int)(l); --i)
using namespace std;

inline int read(){
    int x = 0, fh = 1; char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
    for(; isdigit(ch); ch = getchar()) x = (x<<1) + (x<<3) + (ch^'0');
    return x * fh;
}

const int N = 1000000, M = 2000000 << 1;
const long long inf = 1ll * 0x3f3f3f3f * 0x7f7f7f7f;
int n, m;

struct graph {
    int to[M], Head[N], Next[M], val[M], e;
    void init() {
        e = 0;
        Set(Head, 0);
    }
    void add_edge (int u, int v, int w) {
        to[++e] = v;
        val[e] = w;
        Next[e] = Head[u];
        Head[u] = e;
    }
};
graph G;
#define Travel(i, u, G) for(int i = G.Head[u]; i; i = G.Next[i])

bool inq[N];
int S, T;
void spfa(long long dis[]) {
    queue<int> Q;
	For (i, 1, n) dis[i] = inf;
    Q.push(S); dis[S] = 0;
    while (!Q.empty() ) {
        int now = Q.front(); Q.pop();
        inq[now] = false;
        Travel(i, now, G) {
            int v = G.to[i];
            if (dis[v] > dis[now] + G.val[i]) {
                dis[v] = dis[now] + G.val[i];
                if (!inq[v]) { inq[v] = true; Q.push(v); }
            } 
        }
    }
}

typedef long long ll;
ll dis1[N], dis2[N];

const int Mod = 1e9 + 7;
ll dp1[N], dp2[N], dp[N], dis[N];

ll Dp(int u) {
	if (dp[u]) return dp[u];
    Travel(i, u, G) {
        int v = G.to[i];
        if (dis[u] - G.val[i] == dis[v]) 
            dp[u] = (dp[u] + Dp(v) ) % Mod;
    }
    return dp[u];
}

int main (){
#ifdef zjp_shadow
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
#endif
    G.init();
    n = read(), m = read();
	S = read(), T = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        G.add_edge(u, v, w);
        G.add_edge(v, u, w);
    }
    spfa(dis1); Cpy(dis, dis1); dp[S] = 1; Dp(T); Cpy(dp1, dp);

	Set(dp, 0); dp[T] = 1;

	swap(S, T);
	spfa(dis2); Cpy(dis, dis2); Dp(T); Cpy(dp2, dp);
	swap(S, T);

	long long max_dis = dis1[T];
	long long ans = (ll)dp1[T] * dp1[T] % Mod;

	For (i, 1, n) if (dis1[i] == dis2[i]) 
		(ans += Mod - dp1[i] * dp1[i] % Mod * dp2[i] % Mod * dp2[i] % Mod) %= Mod;
	
	For (i, 1, n)
		for (int j = G.Head[i]; j; j = G.Next[j]) {
			int u = i, v = G.to[j], w = G.val[j];
			if (dis1[u] + dis2[v] + w == max_dis && abs(dis1[u] - dis2[v]) < w)
				(ans += Mod - dp1[u] * dp1[u] % Mod * dp2[v] % Mod * dp2[v] % Mod) %= Mod;
		}
	cout << ans << endl;
}

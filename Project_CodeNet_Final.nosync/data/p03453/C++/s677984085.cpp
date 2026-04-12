#include <bits/stdc++.h>
using namespace std;
#define M 200010
#define LL long long
#define MOD 1000000007
#define inf 2147483647
#define llinf 40000000000000000ll
#define For(i, x, y) for(int i = (x); i < (y); ++ i)
#define rep(i, x, y) for(int i = (x); i <= (y); ++ i)
#define drep(i, x, y) for(int i = (x); i >= (y); -- i)
inline int read(){
	char ch=getchar();int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline LL llread(){
	char ch=getchar();LL x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Edge{
	int u, v, w, Next;
} G[M*2];
int head[M], tot;
inline void add(int u, int v, int w) {
	G[++ tot] = (Edge){u, v, w, head[u]};
	head[u] = tot;
}
struct Node{
	LL d; int u;
	inline bool operator < (const Node& rhs) const {
		return d > rhs.d;
	}
};
priority_queue<Node> Q;
bool done[M];
LL ds[M], dt[M];
LL fs[M], ft[M];
inline void dij(int n, int s, LL d[], LL f[]) {
	memset(done, 0, sizeof(done));
	while(!Q.empty()) Q.pop();
	rep(i, 1, n) d[i] = MOD*200000ll;
	d[s] = 0; Q.push((Node){0, s});
	f[s] = 1;
	while(!Q.empty()) {
		Node x = Q.top(); Q.pop();
		if(done[x.u]) continue;
		done[x.u] = 1;
		for(int i = head[x.u]; i != -1; i = G[i].Next) {
			if(d[G[i].v] > d[x.u] + G[i].w) {
				d[G[i].v] = d[x.u] + G[i].w;
				f[G[i].v] = f[x.u];
				Q.push((Node){d[G[i].v], G[i].v});
			}
			else if(d[G[i].v] == d[x.u] + G[i].w) {
				(f[G[i].v] += f[x.u]) %= MOD;
			}
		}
	}
}

int main() {
	//freopen("08.txt", "r", stdin);
	int n = read(), m = read(), s = read(), t = read();
	memset(head, -1, sizeof(head));
	rep(i, 1, m) {
		int u = read(), v = read(), w = read();
		add(u, v, w); add(v, u, w);
	}
	dij(n, s, ds, fs); dij(n, t, dt, ft);
	//rep(i, 1, n) printf("%d\n", fs[i]);
	LL res = 0;
	rep(i, 1, n) {
		if(ds[i] == dt[i] && ds[i] != MOD * 200000ll) {
			if(ds[i] + dt[i] == ds[t]) {
				res += fs[i] * ft[i] % MOD * fs[i] % MOD * ft[i] % MOD;
				res %= MOD;
			}
		}
	}
//	printf("%lld\n", res);
	rep(i, 1, tot) {
		int x = G[i].u, y = G[i].v;
		if(ds[x] + dt[y] + G[i].w == ds[t]) {
			if(min(ds[x], dt[y]) + G[i].w > max(ds[x], dt[y])) {
				//printf("%lld %lld %lld\n", ds[x], dt[y], G[i].w);
				res += fs[x] * ft[y] % MOD * fs[x] % MOD * ft[y] % MOD;
				res %= MOD;
			}
		}
	}
	//printf("%lld\n", res);
	printf("%lld\n", (fs[t] * ft[s] % MOD - res + MOD) % MOD);
	return 0;
}


# include <bits/stdc++.h>
using namespace std;
namespace Base{
	# define mr make_pair
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	template<typename T> void read(T &x){
    	x = 0; int fh = 1; double num = 1.0; char ch = getchar();
		while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
		while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
	    if (ch == '.'){
	    	ch = getchar();
	    	while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
		}
		x = x * fh;
	}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

const int N = 100010, M = 200010, P = 1e9 + 7;
priority_queue <pair<ll, int> > hp;
struct Edge{
	int data, next, vote;
}e[M * 2];
int head[N], place, p[N], f[N], g[N], ans;
ll dis[N];
void build(int u, int v, int w){
	e[++place].data = v; e[place].next = head[u]; head[u] = place; e[place].vote = w;
}
int n, m, S, T;
void dij(){
	memset(dis, inf, sizeof(dis));
	hp.push(mr(0, S));
	while (hp.size() != 0){
		while (hp.size() > 0 && dis[hp.top().second] != dis[0]) hp.pop();
		if (hp.size() == 0) break;
		int x = hp.top().second;
		dis[x] = -hp.top().first;
		for (int ed = head[x]; ed != 0; ed = e[ed].next)
			if (dis[e[ed].data] == dis[0]) hp.push(mr(-(dis[x] + e[ed].vote), e[ed].data));
	}
}
bool cmp(int x, int y){
	return dis[x] < dis[y];
}
int main(){
	read(n); read(m);
	read(S); read(T);
	for (int i = 1; i <= m; i++){
		int u, v, w; 
		read(u); read(v); read(w);
		build(u, v, w); build(v, u, w);
	}
	dij();
	for (int i = 1; i <= n; i++) p[i] = i;
	sort(p + 1, p + n + 1, cmp);
	f[S] = 1;
	for (int i = 1; i <= n; i++){
		int x = p[i];
		for (int ed = head[x]; ed != 0; ed = e[ed].next)
			if (dis[e[ed].data] == dis[x] + e[ed].vote)
				f[e[ed].data] = (f[e[ed].data] + f[x]) % P;
	}
	g[T] = 1;
	for (int i = 1; i <= n; i++){
		int x = p[n - i + 1];
		for (int ed = head[x]; ed != 0; ed = e[ed].next)
			if (dis[e[ed].data] == dis[x] - e[ed].vote)
				g[e[ed].data] = (g[e[ed].data] + g[x]) % P;
	}
	ans = 1ll * f[T] * f[T] % P;
	for (int i = 1; i <= n; i++){
		int x = i;
		for (int ed = head[x]; ed != 0; ed = e[ed].next)
			if (dis[e[ed].data] == dis[x] + e[ed].vote){
				ll tmp = dis[T] - dis[e[ed].data];
				if (tmp < dis[e[ed].data] && tmp > dis[x] - (dis[e[ed].data] - dis[x]))
					ans = ((ans - 1ll * f[x] * g[e[ed].data] % P * f[x] % P * g[e[ed].data]) % P + P) % P;
			}
	}
	for (int i = 1; i <= n; i++)
		if (dis[i] == dis[T] - dis[i])
		ans = ((ans - 1ll * f[i] * g[i] % P * f[i] % P * g[i]) % P + P) % P;
	printf("%d\n", ans);
	return 0;
}


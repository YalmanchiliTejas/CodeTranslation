#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
inline char nc() {
	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
const int maxn = 1e5 + 5; 
int n;
int f[maxn];
int head[maxn];
struct edge {
	int to, nex;
	edge(int to=0,int nex=0):to(to),nex(nex){} 
};
vector<edge> G;
inline void addedge(int u, int v) {
	G.push_back(edge(v, head[u])), head[u] = G.size() - 1;
	G.push_back(edge(u, head[v])), head[v] = G.size() - 1;
}
bool dfs(int u, int fa) {
	for(int i = head[u]; ~i; i = G[i].nex) {
		int v = G[i].to; if(v == fa) continue;
		if(dfs(v, u)) return 1; 
		f[u] += f[v];
	}
	if(f[u] > 1) return 1;
	f[u] ^= 1;
	return 0;
}
bool solve() {
	return dfs(1, 0) || f[1];
}
int main() {
	read(n);
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; ++i) {
		int u, v; read(u), read(v);
		addedge(u, v);
	}
	puts(solve() ? "First" : "Second");
	return 0;
} 
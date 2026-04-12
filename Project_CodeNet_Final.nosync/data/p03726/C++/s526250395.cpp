#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define PB push_back
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=1e5+10;
vector<int> G[N];
int du[N],vis[N],n;
queue<int> q;
void del(int u) {
	for(int i=0;i<G[u].size();++i) if(!vis[G[u][i]]) {
		du[G[u][i]]--;
		if(du[G[u][i]]==1) q.push(G[u][i]);
	}
	vis[u]=1;
}
	
int main() {
	rd(n);
	for(int x,y,i=1;i<n;++i) {
		rd(x),rd(y);
		G[x].PB(y),G[y].PB(x);
		du[x]++,du[y]++;
	}
	for(int i=1;i<=n;++i) if(du[i]==1) q.push(i);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		if(du[u]!=1) {
			printf("First");
			return 0;
		}
		for(int i=0;i<G[u].size();++i)
			if(!vis[G[u][i]]) { del(G[u][i]); break; }
		del(u);
	}
	for(int i=1;i<=n;++i) if(!vis[i]) { printf("First"); return 0; }
	printf("Second");
	return 0;
}
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 555555;
int n;Vi e[N];bool vis[N];
void dfs(int u, int fa){
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		dfs(e[u][i],u);if(!vis[e[u][i]]&&!vis[u])vis[e[u][i]]=vis[u]=1;
	}
}
int main() {
	read(n);rep(i,2,n){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	dfs(1,0);bool bo=0;rep(i,1,n)bo|=!vis[i];
	if(bo)puts("First");else puts("Second");
	return 0;
}

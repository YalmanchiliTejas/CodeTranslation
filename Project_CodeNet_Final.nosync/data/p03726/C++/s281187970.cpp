#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
struct Edge{int v;Edge*nxt;}pl[N<<1],*cur=pl,*G[N];
inline void ins(int u,int v){*cur=(Edge){v,G[u]},G[u]=cur++;}
int n;
int dfs(int x,int f=-1){
	int p=1;
	Es(x,i)if(i->v!=f)p-=dfs(i->v,x);
	if(p<0)puts("First"),exit(0);
	return p;	
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd();
	if(n&1)puts("First"),exit(0);
	For(i,1,n){
		int u=rd(),v=rd();
		ins(u,v),ins(v,u);
	}
	dfs(1);
	puts("Second");
}
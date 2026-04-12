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
int n,d[N],q[N];
void dfs(int x,int f=-1){
	int sz=0;
	Es(x,i)if(i->v!=f){
		sz+=d[i->v]==1;
		dfs(i->v,x);
	}
	if(sz>1)puts("First"),exit(0);
	else if(sz==1){
		q[x]=1;
	}
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
		d[u]++,d[v]++;
	}
	rep(i,1,n)if(d[i]!=1){
		dfs(i);break;
	}
	rep(i,1,n)if(!q[i]&&d[i]>=2){
		int f=1;
		Es(i,j)f&=q[j->v];
		if(f)puts("First"),exit(0);
	}
	puts("Second");
}
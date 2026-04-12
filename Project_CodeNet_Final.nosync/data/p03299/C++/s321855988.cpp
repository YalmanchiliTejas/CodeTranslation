#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define db double
#define pint pair<int,int>
#define mk(x,y) make_pair(x,y)
#define fir first
#define sec second
#define Rep(x,y,z) for(int x=y;x<=z;x++)
#define Red(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const int MAXN=105,Mod=1e9+7;
char buf[1<<12],*p1=buf,*p2=buf,nc;int ny;
inline char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
//inline char gc(){return getchar();}
inline int read(){
	int x=0;for(ny=1;nc=gc(),(nc<48||nc>57)&&nc!=EOF;)if(nc==45)ny=-1;if(nc<0)return nc;
	for(x=nc-48;nc=gc(),47<nc&&nc<58&&nc!=EOF;x=(x<<3)+(x<<1)+(nc^48));return x*ny;
}inline int Fp(int x,int k){int ans=1;for(;k;k>>=1,x=1ll*x*x%Mod)if(k&1)ans=1ll*ans*x%Mod;return ans;}
int sz[MAXN],len[MAXN],f[MAXN],g[MAXN],num[MAXN],stk[MAXN],id[MAXN],n,ans=1;
vector<int>G[MAXN];
void dfs(int x){
	int ans=1,s=sz[x];f[x]=1,g[x]=0;
	for(int i=0,len=G[x].size(),y;i<len;i++){
		dfs(y=G[x][i]),g[x]=(1ll*g[x]*(f[y]+g[y])+1ll*f[x]*g[y])%Mod,f[x]=1ll*f[x]*f[y]%Mod,s-=sz[y];
	}g[x]=(1ll*g[x]*Fp(2,s)%Mod+1ll*f[x]*(Fp(2,s)-1))%Mod,f[x]=1ll*f[x]*Fp(2,len[x])%Mod;
}
inline int Solve(int l,int r){
	int cnt=0,top=0;stk[0]=l-1;
	Rep(i,l,r){
		while(top&&num[stk[top]]>=num[i])
			if(num[stk[top]]==num[i]){stk[top]=i;break;}
			else if(num[i]>num[stk[top-1]]){
				int v=++cnt;G[v].clear(),G[v].push_back(id[top]),len[id[top]]=num[stk[top]]-num[i];
				sz[id[top]]=i-stk[top-1]-2,stk[top]=i,id[top]=v;break;
			}else len[id[top]]=num[stk[top]]-num[stk[top-1]],sz[id[top]]=i-stk[top-1]-2,G[id[top-1]].push_back(id[top]),top--;
		if(stk[top]!=i){int v=++cnt;stk[++top]=i,id[top]=v,G[v].clear();}
	}while(top){
		len[id[top]]=num[stk[top]]-num[stk[top-1]],sz[id[top]]=r-stk[top-1]-1;
		if(top>1)G[id[top-1]].push_back(id[top]);top--;
	}dfs(id[1]);return (f[id[1]]+g[id[1]])%Mod;
}
int main(){
	n=read();
	Rep(i,1,n)num[i]=read()-1;
	Rep(i,1,n){
		if(!num[i]||!num[i-1])ans=ans*2%Mod;
		if(num[i]&&!num[i+1]){
			int l=i;for(;num[l-1];l--);
			ans=1ll*ans*Solve(l,i)%Mod;
		}
	}cout<<ans<<'\n';
	return 0;
}



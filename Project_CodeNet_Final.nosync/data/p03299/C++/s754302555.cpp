#include <bits/stdc++.h>
#define mod 1000000007
#define N 111
using namespace std;
#define LL long long
LL fpow(LL x,int k){
	LL ans=1;
	while (k){
		if (k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
} 
vector <int> son[N];
int len[N],siz[N],f[N],g[N],num[N],stk[N],id[N];

void dfs(int x) {
	int ans=1,s=siz[x];
	f[x]=1;g[x]=0;
	for (int i=0;i<son[x].size();i++){
		int u=son[x][i];
		dfs(u);
		g[x]=((LL)g[x]*(f[u]+g[u])+(LL)f[x]*g[u])%mod;
		f[x]=(LL)f[x]*f[u]%mod;
		s-=siz[u];
	}
	g[x]=((LL)g[x]*fpow(2LL,s)%mod+(LL)f[x]*(fpow(2LL,s)-1+mod))%mod;
	f[x]=(LL)f[x]*fpow(2LL,len[x])%mod;
} 
int solve(int l,int r){
	int cnt=0,top=0;
	stk[0]=l-1;
	for (int i=l;i<=r;i++){
		while (top&&num[stk[top]]>=num[i])
		if (num[i]==num[stk[top]]){
			stk[top]=i;break;
		}else if (num[i]>num[stk[top-1]]) {
			int v=++cnt;
			son[v].clear();
			son[v].push_back(id[top]);
			len[id[top]]=num[stk[top]]-num[i];
			siz[id[top]]=i-stk[top-1]-2;
			stk[top]=i;id[top]=v;
			break;
		}else{
			len[id[top]]=num[stk[top]]-num[stk[top-1]];
			siz[id[top]]=i-stk[top-1]-2;
			son[id[top-1]].push_back(id[top]);
			top--;
		}
		if (stk[top]!=i){
			int v=++cnt;
			stk[++top]=i;id[top]=v;
			son[v].clear();
		}
	}
	while (top){
		len[id[top]]=num[stk[top]]-num[stk[top-1]];
		siz[id[top]]=r-stk[top-1]-1;
		if (top>1) son[id[top-1]].push_back(id[top]);
		top--;
	}
	dfs(id[1]);
	return (f[id[1]]+g[id[1]])%mod;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
int main(){
	int n=read();
	for (int i=1;i<=n;i++) num[i]=read()-1;
	int ans=1;
	for (int i=1;i<=n;i++){
		if (!num[i] || !num[i-1]) ans=ans*2LL%mod;
		if (num[i] && !num[i+1]){
			int l=i;
			while (num[l-1]) l--;
			ans=ans*solve(l,i)%mod; 
		}
	}
	printf("%d\n",ans);
	return 0;
}
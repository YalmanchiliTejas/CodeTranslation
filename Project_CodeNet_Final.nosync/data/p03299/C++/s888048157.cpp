#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll pow_mod(ll x,int k) {
  ll ans=1;
  while (k) {
  	if (k&1) ans=ans*x%MOD;
  	x=x*x%MOD;
  	k>>=1;
  }
  return ans;
} 

vector <int> son[105];
int len[105],size[105];

int f[105],g[105];

void dfs(int x) {
  int ans=1,s=size[x];
  f[x]=1;g[x]=0;
  for(int i=0;i<son[x].size();i++) {
  	int u=son[x][i];
  	dfs(u);
  	g[x]=((ll)g[x]*(f[u]+g[u])+(ll)f[x]*g[u])%MOD;
  	f[x]=(ll)f[x]*f[u]%MOD;
  	s-=size[u];
  }
  g[x]=((ll)g[x]*pow_mod(2LL,s)%MOD+(ll)f[x]*(pow_mod(2LL,s)-1+MOD))%MOD;
  f[x]=(ll)f[x]*pow_mod(2LL,len[x])%MOD;
} 

int num[105];

int st[105],id[105];

int solve(int l,int r) {
  int cnt=0,top=0;
  st[0]=l-1;
  for(int i=l;i<=r;i++) {
  	while (top&&num[st[top]]>=num[i])
  	  if (num[i]==num[st[top]]) {
  	  	  st[top]=i;
  	  	  break;
		}
	  else if (num[i]>num[st[top-1]]) {
	  	int v=++cnt;
	  	son[v].clear();
	  	son[v].push_back(id[top]);
	  	len[id[top]]=num[st[top]]-num[i];
	  	size[id[top]]=i-st[top-1]-2;
	  	st[top]=i;id[top]=v;
	  	break;
	  }
	  else {
	  	len[id[top]]=num[st[top]]-num[st[top-1]];
	  	size[id[top]]=i-st[top-1]-2;
	  	son[id[top-1]].push_back(id[top]);
	  	top--;
	  }
	if (st[top]!=i) {
		int v=++cnt;
		st[++top]=i;id[top]=v;
		son[v].clear();
	}
  }
  while (top) {
  	len[id[top]]=num[st[top]]-num[st[top-1]];
  	size[id[top]]=r-st[top-1]-1;
  	if (top>1) son[id[top-1]].push_back(id[top]);
  	top--;
  }
  dfs(id[1]);
  return (f[id[1]]+g[id[1]])%MOD;
}

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
  	scanf("%d",&num[i]);
  	num[i]--;
  }
  int ans=1;
  for(int i=1;i<=n;i++) {
    if (!num[i]||!num[i-1]) ans=ans*2LL%MOD;
    if (num[i]&&!num[i+1]) {
    	int l=i;
    	while (num[l-1]) l--;
		ans=ans*solve(l,i)%MOD; 
	}
  }
  printf("%d\n",ans);
  return 0;
}
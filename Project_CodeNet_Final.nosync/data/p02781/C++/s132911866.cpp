#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e2+5;
char s[N];
int n,k;
ll f[N][105];
ll dfs(int pos,int x,bool pre,bool limit) {
	//printf("%d %d %d %d\n",pos,x,pre,limit);
	if(pos==n+1) return pre&&x==k;
	if(~f[pos][x]&&!limit) return f[pos][x];
	int up=limit?(s[pos]-'0'):9;
	ll ans=0;
	for(int i=0;i<=up;i++) {
		if(i) ans+=dfs(pos+1,x+1,true,i==up&&limit);
		else ans+=dfs(pos+1,x,pre,i==up&&limit);
	}
	if(!limit) f[pos][x]=ans;
	return ans;
}
int main() {
	memset(f,-1,sizeof f);
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	ll ans=0;
	ans+=dfs(2,0,false,false);
	int up=s[1]-'0';
	for(int i=1;i<=up;i++) {
		ans+=dfs(2,1,true,i==up);
	}
	printf("%lld\n",ans);
	return 0;
}
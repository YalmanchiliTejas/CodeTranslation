#include <bits/stdc++.h>
using namespace std;
#define N 105
#define M 5
#define ll long long
#define set(a,v) memset(a,v,sizeof(a)) 
int n,m,a[N];ll dp[N][M];
void swp(int &x,int &y) {int t=x;x=y;y=t;} 
void rd(int a[])
{
	char c=0;while(!isdigit(c)) c=getchar();
	while(isdigit(c)) a[++n]=c&15,c=getchar();
	for(int i=1;i<=n>>1;++i) swp(a[i],a[n-i+1]);
}
ll dfs(int u,bool lim,int cnt)
{
	if(cnt>m) return 0;if(!u) return cnt==m;
	if(!lim && ~dp[u][cnt]) return dp[u][cnt];
	ll res=0;int up=lim?a[u]:9;
	for(int i=0;i<=up;++i) res+=dfs(u-1,lim&(i==up),cnt+(i!=0));
	if(!lim) dp[u][cnt]=res;return res;
}
int main()
{
	rd(a);scanf("%d",&m);set(dp,-1);
	printf("%lld\n",dfs(n,1,0));return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gc getchar()
#define N 100010
#define pb push_back
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
int no_ans,f[N],g[N];vector<int> t[N];
int dfs(int x,int fa=0)
{
	if(no_ans) return 0;int n=(int)t[x].size();
	if(fa&&n==1) return f[x]=1,g[x]=0;int c=0,fc=0;
	for(int i=0,y;i<n;i++) if((y=t[x][i])^fa)
		dfs(y,x),c+=(g[y]==0),fc|=f[y];
	if(c==0) f[x]=1,g[x]=fc;
	else if(c==1) f[x]=0,g[x]=1;
	else f[x]=g[x]=0,no_ans=1;
	return 0;
}
int main()
{
	int n=inn();if(n&1) return !printf("First\n");
	for(int i=1,u,v;i<n;i++) u=inn(),v=inn(),t[u].pb(v),t[v].pb(u);
	return dfs(1),!printf("%s\n",(no_ans||!g[1])?"First":"Second");
}
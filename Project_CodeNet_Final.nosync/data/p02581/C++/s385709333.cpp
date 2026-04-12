#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=2005;
int a[maxn*3];
int n;
int dp[maxn][maxn],g[maxn][maxn];
int f[maxn];
vector<pair<int,int> > mem;
inline void upd(int i,int j,int x){
	g[i][j]=max(g[i][j],x);
	mem.push_back(make_pair(i,j));
	//f[i]=max(f[i],x);
	//f[j]=max(f[j],x);
}
int curmax=0;
inline void clermem(){
	for(int i=0;i<mem.size();i++){
		int u=mem[i].first,v=mem[i].second;
		dp[u][v]=max(g[u][v],dp[u][v]);
		curmax=max(curmax,dp[u][v]);
		f[u]=max(f[u],dp[u][v]);
		f[v]=max(f[v],dp[u][v]);
	}
	mem.clear();
}
int main(){
	//freopen("data.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n*3;i++){
		scanf("%d",&a[i]);
	}
	memset(dp,0xf3,sizeof(dp));
	memset(g,0xf3,sizeof(g));
	memset(f,0xf3,sizeof(f));
	dp[a[1]][a[2]]=dp[a[2]][a[1]]=0;
	g[a[1]][a[2]]=g[a[2]][a[1]]=0;
	f[a[1]]=f[a[2]]=0;
	int tag=0;
	for (int i=3;i+2<=n*3;i+=3){
		vector<int> cur;
		cur.push_back(a[i]);
		cur.push_back(a[i+1]);
		cur.push_back(a[i+2]);
		sort(cur.begin(),cur.end());
		if (a[i]==a[i+1]&&a[i+1]==a[i+2]){
			tag++;
			continue;
		}
		int a1,a2,a3;
		if (cur[0]==cur[1]){
			a1=cur[0],a2=cur[1];
			a3=cur[2];
		}
		else if (cur[1]==cur[2]){
			a1=cur[1],a2=cur[2];
			a3=cur[0];
		}
		else{
			a1=cur[0],a2=cur[1];
			a3=cur[2];
		}
		if (a1==a2){
			// case 1: 2
			for (int i=1;i<=n;i++){
				upd(i,a3,dp[a1][i]+1);
				upd(a3,i,dp[a1][i]+1);
			}
			// case 
		}
		for (int i=1;i<=n;i++){
			upd(i,a3,f[i]);
			upd(a3,i,f[i]);
		}
		for (int i=1;i<=n;i++){
			upd(i,a2,f[i]);
			upd(a2,i,f[i]);
		}
		for (int i=1;i<=n;i++){
			upd(i,a1,f[i]);
			upd(a1,i,f[i]);
		}
		upd(a1,a2,curmax);
		upd(a2,a1,curmax);
		upd(a1,a2,dp[a3][a3]+1);
		upd(a2,a1,dp[a3][a3]+1);
		upd(a2,a3,curmax);
		upd(a3,a2,curmax);
		upd(a2,a3,dp[a1][a1]+1);
		upd(a3,a2,dp[a1][a1]+1);
		upd(a1,a3,curmax);
		upd(a3,a1,curmax);
		upd(a1,a3,dp[a2][a2]+1);
		upd(a3,a1,dp[a2][a2]+1);
		clermem();
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j&&i==a[n*3]){
				ans=max(ans,dp[i][j]+tag+1);
			}
			else{
				ans=max(ans,dp[i][j]+tag);
			}
		}
	}
	cout<<ans<<endl;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int vis[3005][3005];
long long dp[3005][3005];
int a[3005];
long long min_(long long x,long long y) {return x>y?y:x;}
long long max_(long long x,long long y) {return x>y?x:y;}
long long dfs(int l,int r) {
	if(l>r) return 0;
	if(vis[l][r]) return dp[l][r];
	vis[l][r]=true;
	int d=n-(r-l+1);
	if(d & 1) {
		dp[l][r]=min_(dfs(l+1,r)-a[l],dfs(l,r-1)-a[r]);           //Jino删数 
	}
	else {
		dp[l][r]=max_(dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
	}
	return dp[l][r];
}
int main () {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
    cout<<dfs(1,n);
    
}
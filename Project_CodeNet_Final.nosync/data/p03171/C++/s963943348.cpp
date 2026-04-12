#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x<0){
		putchar('-'),write(-x);
		return;
	}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[3003];
bool vis[3003][3003];
ll dp[3003][3003];
ll dfs(int l,int r,bool u){
	if (l==r){
		if (u) return a[l];
		return -a[l];
	}
	if (vis[l][r]) return dp[l][r];
	vis[l][r]=1;
	if (u) dp[l][r]=max(dfs(l+1,r,0)+a[l],dfs(l,r-1,0)+a[r]);
	else dp[l][r]=min(dfs(l+1,r,1)-a[l],dfs(l,r-1,1)-a[r]);
	return dp[l][r];
}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	write(dfs(1,n,1));
}
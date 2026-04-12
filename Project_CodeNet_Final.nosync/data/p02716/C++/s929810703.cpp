#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int Maxn=2e5+5;
int n,vis[2][Maxn];
long long a[Maxn],f[Maxn],dp[2][Maxn];
long long findou(int nowy)
{
	if(nowy==n+1)return 0;
	if(vis[0][nowy])return dp[0][nowy];
	else vis[0][nowy]=1;
	return dp[0][nowy]=max(a[nowy]+findou(nowy+2),f[nowy+1]);
}
long long findji(int nowy)
{
	if(nowy==n)return 0;
	if(vis[1][nowy])return dp[1][nowy];
	else vis[1][nowy]=1;
	return dp[1][nowy]=max(a[nowy]+findji(nowy+2),findou(nowy+1));
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i-=2)
		f[i]=f[i+2]+a[i];
	if(n%2)cout<<findji(1);
	else cout<<findou(1);
	return 0;
}
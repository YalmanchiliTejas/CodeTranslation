#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int const MAXN=3010;
#define ll long long
ll n, v[MAXN];
ll memo[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll dp(int i, int j){
	if(i==j)	return v[i];
	if(i>j)	return 0;
	if(vis[i][j])
		return memo[i][j];
	vis[i][j]=true;
	ll l=v[i]-dp(i+1,j), r=v[j]-dp(i,j-1);
	return memo[i][j]=max(l,r);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<dp(0,n-1);
}
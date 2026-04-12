/*
ABHIJEET BISWAS
CSE 4th SEM 
MNNIT ALLAHBAD
https://atcoder.jp/contests/dp/tasks/dp_l
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e18
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define MAX 1000009
#define pb push_back
#define mp map<int,int>
#define f first
#define s second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ld pi=2.0*acos(0.0);
ll dp[3001][3001][2];
ll arr[3003];
ll n;
ll solve(int a,int b,int p)
{
	if(a>b)
	return 0;
	if(dp[a][b][p]!=-1)
	return dp[a][b][p];
	ll p1=solve(a+1,b,(p+1)%2)+ ((p==0)?arr[a]:-1*arr[a]);
	ll p2=solve(a,b-1,(p+1)%2)+ ((p==0)?arr[b]:-1*arr[b]);
	if(p==0)
	return dp[a][b][p]=max(p1,p2);
	else
	return dp[a][b][p]=min(p1,p2);
	
	
}
int main() {
	fastIO
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=0;k<2;k++)
	dp[i][j][k]=-1;
	cout<<solve(1,n,0)<<endl;
	return 0;
}
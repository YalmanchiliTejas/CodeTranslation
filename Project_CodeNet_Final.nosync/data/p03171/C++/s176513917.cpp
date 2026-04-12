/**
 *   Author: Praveen Ojha
 *   Created: 27 March 2019
 *   Time: 02:18:06
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define PI 3.141592653589793238510
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define __ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
typedef long double ld;
typedef pair<int,int> pii;
const int maxn=3005;
int n,a[maxn],dp[maxn][maxn];
int solve(int start,int end){
	if(start==end)
	return a[start];
	if(dp[start][end]!=-1)
		return dp[start][end];
	return dp[start][end]=max(a[start]-solve(start+1,end),a[end]-solve(start,end-1));
}
int32_t main(){__
	memset(dp,-1,sizeof dp);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<solve(0,n-1)<<"\n";
return 0;
}
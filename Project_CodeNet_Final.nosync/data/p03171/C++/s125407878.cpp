/*
 It's better to sleep happy and tired rather than disappointed and frustrated
 There's only 1 thing that's impossible and that is defeating a man who doesn't give up
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mx2 102
#define mx3 1003
#define mx4 10004
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define PI 3.14159265
#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(int i=0 ; i<n ; i++)
#define Fo(i,k,n) for(int i=k ; i<n ; i++)
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pair<int,int>,int> piii;

const int inf=0x3f3f3f3f;
int n , ans , sum , a , b ,arr[mx5];
ll dp[3000][3000][2];
string str;

ll solve(int l ,  int r,int t)
{
	if(r-l<0)
	{
		return 0;
	}
	if(dp[l][r][t]!=-1)
	{
		return dp[l][r][t];
	}
	dp[l][r][t]=(t==0? max(solve(l+1,r,1)+arr[l] , solve(l,r-1,1)+arr[r]) : min(solve(l+1,r,0)-arr[l] , solve(l,r-1,0)-arr[r]));
	// cout<<l<<" "<<r<<" "<<t <<" " << dp[l][r][t]<<"\n";
	return dp[l][r][t];
}

int main() {
	ios::sync_with_stdio(false);
	//int t;cin>>t;while(t--)
	{
		cin>>n;
		fo(i,n)cin>>arr[i];
		memset(dp,-1,sizeof(dp));
		cout<<solve(0,n-1,0);
	}
	return 0;
}

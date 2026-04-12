#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
ll dp[3001][3001];
ll  solve(int i,int j,ll a[]){
	if(i==j)
		return dp[i][j]=a[i];
	else if(j==i+1)
		return dp[i][j]=max(a[i],a[j]);
	else if(dp[i][j]!=0)
		return dp[i][j];
	return dp[i][j]=max(a[i]+min(solve(i+2,j,a),solve(i+1,j-1,a)),a[j]+min(solve(i,j-2,a),solve(i+1,j-1,a)));	
}
int main(){
	for(int i=0;i<101;i++)
	for(int j=0;j<101;j++)dp[i][j]=0;
	int n;
	cin>>n;
	ll a[n];
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll mx=solve(0,n-1,a);
	ll ans=2*mx-sum;
	cout<<ans<<endl;
}


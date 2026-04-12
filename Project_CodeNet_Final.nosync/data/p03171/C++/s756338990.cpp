#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fn(int i,int j,vector<ll>& v,vector<vector<ll> >& dp,vector<vector<ll> >& s){
	if(i==j){
		dp[i][j]=v[i];
		s[i][j]=0;
		return;
	}
	
	if(dp[i+1][j]==-1)
		fn(i+1,j,v,dp,s);
	if(dp[i][j-1]==-1)
		fn(i,j-1,v,dp,s);
	

	ll t1=v[i]+s[i+1][j],t2=s[i][j-1]+v[j];

	if(t1>t2){
		dp[i][j]=t1;
		s[i][j]=dp[i+1][j];
	}
	else{
		dp[i][j]=t2;
		s[i][j]=dp[i][j-1];
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;cin>>n;
	vector<ll> v(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];

	vector<vector<ll> > dp(n,vector<ll> (n,-1));
	vector<vector<ll> > s(n,vector<ll> (n,-1));
	
	fn(0,n-1,v,dp,s);
	cout<<dp[0][n-1]-s[0][n-1]<<endl;

	return 0;
}
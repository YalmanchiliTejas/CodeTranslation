#include<iostream>
#include<utility>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<cstring>
#define nax 100001
#define INF 1e9+5
#define mod 1000000007
#define ll long long int
using namespace std;
ll n=0;
ll tu(int i,int j,vector<ll> &v,vector<vector<ll> > &dp){
	if(dp[i][j]!=INF){
		return dp[i][j];
	}
	int turn=n-(j-i);
	ll d;
	if(turn%2==0){
		d=max(v[i]+tu(i+1,j,v,dp),v[j-1]+tu(i,j-1,v,dp));
	}
	if(turn%2==1){
		d=min(-v[i]+tu(i+1,j,v,dp),-v[j-1]+tu(i,j-1,v,dp));
	}
	return dp[i][j]=d;
}
int main(){
	cin >> n;
	vector <ll> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	vector<vector<ll> > dp(n+1,vector<ll> (n+1,INF));
	for(int i=0;i<n+1;i++){
		dp[i][i]=0;
	}
	tu(0,n,v,dp);
	cout << dp[0][n];
	return 0;
}

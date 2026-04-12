#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
ll dp[3001][3001];

ll taro(ll start,ll end){
	if(start==end){
		return v[start];
	}
	if(start>end){
		return 0;
	}
	if(dp[start][end]==-1){
		ll a=v[start]+min(taro(start+2,end),taro(start+1,end-1));
		ll b=v[end]+min(taro(start+1,end-1),taro(start,end-2));
		dp[start][end]=max(a,b);
	}	
	return dp[start][end];
}

int main(){
 ll n;
 cin>>n;
 ll sum=0;
 for(ll i=0;i<n;i++){
 	ll d;
 	cin>>d;
 	sum+=d;
	v.push_back(d);
 }
 memset(dp,-1,sizeof dp);
 ll x=0,y=0;
 ll ans=taro(0,n-1);
 cout<<2*ans-sum<<endl;
 
 return 0;
}
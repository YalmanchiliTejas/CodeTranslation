#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)



ll n;vector<ll> v;
ll dp[3009][3009];
ll fun(int a,int b){
	ll &ref = dp[a][b];
	if(ref!=-1)
		return ref;
	ref = max(v[a]-fun(a+1,b),v[b]-fun(a,b-1));
	return ref;
}
int main(){
	fast;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	ll sum=0;
	for(ll i=0;i<n;++i){
		ll c;cin>>c;v.push_back(c);	
		sum +=c;
		dp[i][i] = c;
	}
	/*for(int i=0;i<n-1;++i){
		dp[i][i+1] = abs(arr[i]-arr[i+1]);
	}*/
	cout<<fun(0,n-1);
	
	return 0;
}

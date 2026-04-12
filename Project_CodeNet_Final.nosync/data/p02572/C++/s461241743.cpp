//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;
const int M           	= 1e9 + 7;

ll dp[N];
int main(){
	
	ll n;
	cin>>n;

	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}	

	dp[n-1] = a[n-1];
	for(ll i=n-2;i>=0;i--){
		dp[i]  = dp[i+1] + a[i];
		dp[i] %= M;
	}
	ll sum = 0;
	for(ll i=0;i<n-1;i++)
		sum += (dp[i+1]*a[i]),
		sum %= M;

	cout<<sum<<endl;
	

	return 0;
}
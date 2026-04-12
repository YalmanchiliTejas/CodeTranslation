#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
const ll mod=(1e9+7);
int main(){IOS;
	int n;
	cin>>n;
	vector<ll>a(n);
	ll sol=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sol+=a[i];
   if(sol>mod)
   sol%=mod;}
		ll sum=0;
		for(int i=0;i<n;i++){
		    sol-=a[i];
             if(sol<0)
             sol+=mod;
				  sum+=ll(a[i]*(sol))%mod;}
	
				  cout<<sum%mod<<endl;}
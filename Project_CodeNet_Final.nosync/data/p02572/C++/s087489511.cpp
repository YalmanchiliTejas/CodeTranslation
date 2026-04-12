#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mxn=1e5+5;
const int inf=1e9;
const ll mod=1e9+7;
int main() {
	
	int n;cin>>n;

	ll a[n+1];
	a[0]=0;

	ll t=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		t+=a[i];
		t%=mod;
	}


	ll ans=0;
	for(int i=1;i<=n;i++) {
		ll cur=(t-a[i]+mod)%mod;

		ans+= a[i]*cur;
		ans=ans%mod;
	}


	ll  mi=(mod+1)/2;

	cout<<(ans*mi)%mod<<endl;



}
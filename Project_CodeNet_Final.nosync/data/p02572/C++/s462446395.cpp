#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main(){
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	ll suf[n];
	suf[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		suf[i]=(suf[i+1]+a[i])%mod;
	}
	ll ans=0;
	for(int i=0;i+1<n;i++){
		ans=(ans+a[i]*suf[i+1])%mod;
	}
	cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	ll k[n]={};
	k[n-1]=a[n-1];
	for(int i=n-1; i>0; i--){
		k[i-1]=(k[i]+a[i-1])%1000000007;
	}
	ll ans=0;
	for(int i=0; i<n-1; i++){
		ans+=(a[i]*k[i+1])%1000000007;
		ans=ans%1000000007;
	}
	cout<<ans<<endl;
}
		
	
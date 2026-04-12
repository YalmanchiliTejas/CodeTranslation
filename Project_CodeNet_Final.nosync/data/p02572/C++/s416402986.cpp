#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define m 1000000007
using namespace std;
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	ll suff[n];
	suff[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		suff[i]=((a[i]%m)+(suff[i+1]%m))%m;
	}
	ll ans=0;
	for(int i=0;i<n-1;i++){
		ans+=(a[i]*suff[i+1])%m;
		ans=ans%m;
	}
	cout<<ans;
}

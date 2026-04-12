#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m=1e9+7;
int main()
{
	ll n;
	cin>>n;
	ll a[n],res=0;
	for(int i=0;i<n;i++) cin>>a[i];
	ll r[n];
	r[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--) r[i]=(a[i]+r[i+1])%m;
	for(int i=0;i<n-1;i++) res=(res+(a[i]*r[i+1])%m)%m;
	cout<<res;
	return 0;
}
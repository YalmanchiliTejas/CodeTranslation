#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll read() {
	ll x=0, f=1; char ch=' ';
	while(!isdigit(ch)) {ch=getchar(); if(ch=='-') f=-1;}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
	return x*f;
}
ll now, ans, n;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		ll a=read();
		ans=(ans+now*a)%mod;
		now+=a;
		now%=mod;
	}
	cout<<ans;
}

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const ll mod=1e9+7;
ll suf[maxn],a[maxn];

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) suf[i]=(suf[i+1]+a[i])%mod;
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+(a[i]*suf[i+1])%mod)%mod;
	cout<<ans; 
	return 0;	
} 
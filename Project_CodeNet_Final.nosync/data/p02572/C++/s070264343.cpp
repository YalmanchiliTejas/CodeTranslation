#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,a[200005],sum,sum2;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum=(sum+a[i])%mod,sum2=(sum2+1ll*a[i]*a[i])%mod;
	cout<<(1ll*sum*sum-sum2+mod)%mod*((mod+1)/2)%mod;
	return 0;
}
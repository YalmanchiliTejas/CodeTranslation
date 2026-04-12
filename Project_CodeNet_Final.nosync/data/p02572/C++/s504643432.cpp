#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=int(1e9+7);

int main() {
	ll n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	ll suffix[n+2];
	memset(suffix,0,sizeof(suffix));
	for(int i=n-1;i>=0;i--)
	suffix[i]=((suffix[i+1]%mod)+(a[i]%mod))%mod;
	
	ll sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum=(((a[i]%mod)*(suffix[i+1]%mod))%mod + (sum%mod))%mod;
    }
	
	cout<<sum;
	return 0;
}

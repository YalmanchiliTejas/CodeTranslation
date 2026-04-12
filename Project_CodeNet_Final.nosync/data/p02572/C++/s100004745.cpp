#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
int a[200050];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	long long sum = 0;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
		sum += a[i];
	}
	
	long long ans = 0;
	for(int i = 1;i<=n-1;++i){
		sum -= a[i];
		ans += sum%mod*a[i]%mod;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a[n];
	long long sum =0 ;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum+= a[i];
	}
	long long ans = 0;
	for(int i=0;i<n;i++){
		sum -= a[i];
		ans += ((sum%mod)*a[i])%mod;
		ans = ans%mod;
	}
	cout<<ans<<endl;
	 return 0;
}
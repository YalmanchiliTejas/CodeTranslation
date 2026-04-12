#include <bits/stdc++.h>
 
using namespace std;

#define mod 1000000007
 
int main(){
    int n;
	cin>>n;
	long long arr[n];
	long long sum[n];
	sum[0] = arr[0];
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 1;i<n;i++){
		sum[i] = sum[i-1] + arr[i];
	}
	long long ans = 0;
	for(int i = 0;i<n;i++){
		ans += (arr[i] * ((sum[n-1] - sum[i])%mod) % mod);
		ans %= mod;
	}
	if(ans < 0){
		ans += mod;
	}
	cout<<ans;
    return 0;
}
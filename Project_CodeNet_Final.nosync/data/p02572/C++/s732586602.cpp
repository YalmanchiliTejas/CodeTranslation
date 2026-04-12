#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+10;
const int mod = 1e9+7;

int a[maxn];
ll sum[maxn];
int main(void){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
		sum[i] %= mod;	
	}
	ll ans = 0;
	for(int i = 1; i < n; i++){
		ans += a[i]*(sum[n]-sum[i] + mod) % mod;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	long long a[n];
	for(auto &x:a) cin >> x;
	long long sum = accumulate(a, a+n, 0ll);
	sum %= (long long)(1e9+7);
	long long mod = 1e9+7;
	long long ans=0ll;
	for(int i=0; i<n; ++i){
		sum = (sum+mod)%mod;
		sum -= a[i];
		ans += a[i]*sum;
		ans %= (long long)(1e9+7);
		//cout << ans << endl;
	}
	ans = (ans+mod)%mod;
	cout << ans << endl;
}

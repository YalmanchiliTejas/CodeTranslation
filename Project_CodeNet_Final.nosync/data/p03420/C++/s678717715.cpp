#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	if(k == 0){
		cout << n * n << endl;
		return 0;
	}
	for(ll b = k + 1; b <= n; b++){
		ll left = k;
		ll right = b - left;
		ll len = left + right;
		ans += (n + 1) / len * right;
		if((n + 1) / len) ans += max<ll>((n + 1) % len - left, 0);
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printv(vector<ll> v){
	for(int i = 0; i < v.size(); i++){
		printf("%lld ", v[i]);
	}
	printf("\n");
}

int main(void){
	const ll M = 1000000007;
	ll n, ans = 0, temp = 0;
	cin >> n;
	vector<ll> a(n), v;
	for(ll i = 0; i < n; i++) cin >> a[i];
	for(ll i = n-1; i > 0; i--){
		temp += a[i];
		temp %= M;
		v.push_back(temp);
	}
	for(ll i = 0; i < n-1; i++){
		ans += a[i] * v[n-2-i];
		ans %= M;
	}
	//printv(a);
	//printv(v);
	cout << ans << endl;
	return 0;
}

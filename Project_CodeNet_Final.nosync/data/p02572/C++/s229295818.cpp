#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> p(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0){
			p[i] = a[i];
		}else{
			p[i] = (p[i-1] + a[i] ) % MOD;
		}
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		ll tmp = a[i] * (p[n-1] - p[i] + MOD) % MOD;
		res = (res + tmp)%MOD;
	}
	cout << res << "\n";
	return 0;
}

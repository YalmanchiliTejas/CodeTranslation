#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x, m, ans, id[100100], sum[1001001];

ll f(ll n, ll x){
	ll re = 0;
	for(ll i=1;i<=n;i++){
		re += x;
		x = (x * x) % m;
	}
	return re;
}

int main(){
	cin >> n >> x >> m;

	for(ll i=1;i<=n;i++){
		if(id[x]){
			ll left = n - i + 1;
			ll sz = i - id[x];

			ll s = 0;
			for(ll j=id[x];j<i;j++) s += sum[j];

			ans += (left / sz) * s;
			ans += f(left % sz, x);
			break;
		}

		ans += x;
		id[x] = i;
		sum[i] = x;
		x = x * x % m;
	}

	cout << ans;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;

#define MOD 1000000007

ll pow (ll a, ll n) {
	if (n==0)
		return 1;
	if (n==1)
		return a;
	ll tmp = pow (a, n/2) % MOD;
	ll tmp2 = (tmp*tmp) % MOD;
	if (n%2==0) {
		return tmp2;
	}
	return (tmp2*a) % MOD;
}

int main () {
	int N;
	cin >> N;
	ll sum = 0, sq = 0;
	for (int i=0; i<N; i++) {
		ll tmp;
		cin >> tmp;
		sum += tmp;
		sum %= MOD;
		sq += tmp*tmp;
		sq %= MOD;
	}
	ll ans = sum*sum;
	ans %= MOD;
	ans += MOD - sq;
	ans %= MOD;
	ans *= pow (2, MOD-2);
	ans %= MOD;
	
	cout << ans << endl;
	return 0;
}
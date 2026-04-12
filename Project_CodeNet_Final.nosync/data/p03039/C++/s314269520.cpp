#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

ll N, M, Q, A, B, C, D, E, X, Y, Z, arr[1000005];

string s;

const ll mod = 1000000007;

ll mod_inv(ll base){
	ll ans = 1, expo = 1000000005;
	while (expo){
		if (expo & 1){
			ans *= base;
		}
		base *= base;
		base %= mod;
		ans %= mod;
		expo >>= 1;
	}
	return ans;
}

ll choose(ll n, ll k){
	return (((arr[n]*mod_inv(arr[k]))%mod)*mod_inv(arr[n-k]))%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> A;
	arr[0] = 1;
	for (ll i = 1; i <= 1000000; ++i){
		arr[i] = arr[i-1]*i;
		arr[i] %= mod;
	}
	ll tot = 0;
	for (ll i = 1; i < N; ++i){
		tot += (((N-i)*((((M*M)%mod)*i)%mod)%mod)*((choose(N*M-2,A-2))%mod))%mod;
		tot %= mod;
	}
	for (ll i = 1; i < M; ++i){
		tot += (((M-i)*((((N*N)%mod)*i)%mod)%mod)*((choose(N*M-2,A-2))%mod))%mod;
		tot %= mod;
	}
	cout << tot << '\n';
}
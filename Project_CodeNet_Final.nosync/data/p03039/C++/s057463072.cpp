#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
const ll max_n = 200003;
vector<ll> fact(max_n);
bool fact_init = false;

ll pow(ll a, ll b){
	if(a == 0) return 0;
	if(b == 0) return 1;
	if(b % 2 == 1) return a * pow(a, b - 1) % MOD;

	ll d = pow(a, b / 2) % MOD;
	return d * d % MOD;
}

ll comb(ll n, ll k){
	if(!fact_init){
		fact[0] = 1;
		fact[1] = 1;

		for(ll i = 2; i < max_n; i++){
			fact[i] = fact[i-1] * i;
			fact[i] %= MOD;
		}

		fact_init = true;
	}

	ll ret = fact[n];
	ret *= pow(fact[k],MOD-2);
	ret %= MOD;
	ret *= pow(fact[n-k],MOD-2);
	ret %= MOD;

	return ret;

	// X^(-1) = X^(p-2) (mod p) (Fermat's little theorem)
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M, K;
	cin >> N >> M >> K;

	ll cnt = comb(N * M - 2, K - 2);

	ll ans = 0;
	for(ll d = 1; d < M; d++){
		ll t = cnt * N * N;
		t %= MOD;
		t *= d * (M - d);
		t %= MOD;

		ans += t;
		ans %= MOD;
	}

	for(ll d = 1; d < N; d++){
		ll t = cnt * M * M;
		t %= MOD;
		t *= d * (N - d);
		t %= MOD;

		ans += t;
		ans %= MOD;
	}

	cout << ans << endl;
}

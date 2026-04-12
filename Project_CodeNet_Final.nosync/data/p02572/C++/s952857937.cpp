#include"bits/stdc++.h"

#define rep(i, N) for(ll i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i, N)cin >> A[i];

	vector<ll> S(N);
	S[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		S[i] = (S[i + 1] + A[i])%mod;
	}

	ll ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ans += (A[i] * S[i + 1])%mod;
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}
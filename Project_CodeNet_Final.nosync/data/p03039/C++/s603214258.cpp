#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

ll mod = 1e9 + 7;
ll modpow(ll A, ll B) {
	if (B == 0) return 1;
	if (B % 2) return A * modpow(A, B - 1) % mod;
	ll half = modpow(A, B / 2);
	return half * half % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	int N, M, K;
	cin >> N >> M >> K;

	int kei = N + M;

	ll pea = 1ll * K * (K - 1) / 2 % mod;
	
	ll masu = N * M;
	ll kumi = 1;
	rep(i, K) {
		kumi *= masu - i;
		kumi %= mod;
	}
	ll waru = 1;
	rep1(i, K) {
		waru *= i;
		waru %= mod;
	}
	kumi = kumi * modpow(waru, mod - 2) % mod;

	kumi = kumi * pea % mod;
	kumi = kumi * kei % mod;
	kumi = kumi * modpow(3, mod - 2) % mod;

	co(kumi);

	Would you please return 0;
}
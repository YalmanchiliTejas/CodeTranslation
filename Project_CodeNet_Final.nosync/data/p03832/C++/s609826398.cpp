#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui; 
ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x%mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}
int main(){
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	ll sum[1001] = {}; sum[0] = (ll)1;
	ll per[1001], invper[1001];
	per[0] = (ll)1; invper[0] =1;
	for (ll i = 1; i <= 1000; i++) {
		per[i] = per[i - 1] * i%MOD;
	}
	for (ll i = 1; i <= 1000; i++) {
		invper[i] = mod_pow(per[i], MOD - 2, MOD);
	}
	ll superinvper[1001][1001];
	for (ll i = 0; i <= 1000; i++) {
		superinvper[i][0] = (ll)1;
		for (ll j = 1; j <= 1000; j++) {
			superinvper[i][j] = superinvper[i][j - 1] * invper[i] % MOD;
		}
	}
	for (int i = a; i <= b; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (sum[j] > 0) {
				for (int k = c; k <= d; k++) {
					if (j + i * k <= n) {
						sum[j + i * k] = (sum[j + i * k] + ((((sum[j] * per[n - j]) % MOD)*superinvper[i][k] % MOD)*invper[n-j-i*k]%MOD)*invper[k]%MOD) % MOD;
					}
				}
			}
		}
	}
	cout << sum[n] << endl;
	char nyaa;
	std::cin >> nyaa;
	return 0;
}
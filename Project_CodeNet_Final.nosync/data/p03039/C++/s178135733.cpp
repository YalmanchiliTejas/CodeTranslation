#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;


const int INF = 1000000000;
const ll BIG_NUM = 1000000000000000000;


int main() {
	int n, m, k;
	cin >> n >> m >> k;

	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll cnt = ((n - i) * m) % MOD_CONST;
		cnt = (cnt * m) % MOD_CONST;
		ans = (ans + (cnt * i) % MOD_CONST) % MOD_CONST;
	}

	for (int i = 1; i < m; i++) {
		ll cnt = ((m - i) * n) % MOD_CONST;
		cnt = (cnt * n) % MOD_CONST;
		ans = (ans + (cnt * i) % MOD_CONST) % MOD_CONST;
	}

	vector<ll> facto(n * m);
	vector<ll> inv_mod(n * m);
	vector<ll> inv_facto(n * m);

	facto[0] = inv_mod[1] = inv_facto[0] = 1;
	for (int i = 2; i < n * m; i++) {
		inv_mod[i] = (MOD_CONST - (inv_mod[MOD_CONST % i] * (MOD_CONST / i)) % MOD_CONST) % MOD_CONST;
	}


	for (int i = 1; i < n * m; i++) {
		facto[i] = (i * facto[i - 1]) % MOD_CONST;
		inv_facto[i] = (inv_mod[i] * inv_facto[i - 1]) % MOD_CONST;
	}

	ans = (ans * facto[n * m - 2]) % MOD_CONST;
	ans = (ans * inv_facto[k - 2]) % MOD_CONST;
	ans = (ans * inv_facto[n * m - k]) % MOD_CONST;
	cout << ans << endl;
}



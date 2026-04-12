#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false)

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int max_N = 1e3 + 10;
const ll mod = 1e9 + 7;
map<int, int> dp[max_N][max_N];
ll cum[max_N][max_N];
ll fact[max_N], finv[max_N];

ll choose(int N, int K);
ll choose_extend(int N, int k, int j);
ll fast_pow(ll a, ll b);

int main()
{
	fact[0] = 1; finv[0] = 1;
	for (int i = 1; i < max_N; ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
		finv[i] = fast_pow(fact[i], mod - 2);
	}

	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	dp[0][A - 1][0] = 1;
	cum[0][A - 1] = 1;
	for (int i = 0; i <= N; ++i) {
		for (int j = A; j <= B; ++j) {
			dp[i][j][0] += cum[i][j - 1];
			dp[i][j][0] %= mod;
			cum[i][j] = dp[i][j][0];
//			fprintf(stderr, "(%d, %d): ", i, j);
			for (int k = C; k * j <= i && k <= D; ++k) {
				ll temp = (choose(i, k * j) * cum[i - k * j][j - 1]) % mod;
				temp *= choose_extend(k * j, k, j);
				temp %= mod;
//				fprintf(stderr, "%d %lld, ", k, temp);
				dp[i][j][k] += temp;
				dp[i][j][k] %= mod;
				cum[i][j] += dp[i][j][k];
				cum[i][j] %= mod;
			}
			dp[i][j].clear();
//			cerr << endl;
//			fprintf(stderr, "(%d, %d)->(%lld) ", i, j, cum[i][j]);
		}
//		cerr << endl;
	}

	cout << cum[N][B] << endl;
}

ll fast_pow(ll a, ll b)
{
	a %= mod;
	ll ans = 1, res = a;
	while(b) {
		if (b % 2) {
			ans *= res;
			ans %= mod;
		}
		b /= 2;
		res *= res;
		res %= mod;
	}
	return ans;
}

ll choose(int N, int K)
{
	return (fact[N] * ((finv[K] * finv[N - K]) % mod)) % mod;
}

ll choose_extend(int N, int k, int j)
{
	return (fact[N] * ((fast_pow(finv[j], k) * finv[k]) % mod)) % mod;
}

#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

int main() {
	ll N, K;
	cin >> N >> K;
	ll ans = 0;
	for (ll b = K + 1;b <= N;b++) {
		ans += (N / b) * (b - K);
		ll rest = N % b;
		if(rest > 0)
			ans += max(0LL, rest - max(0LL, (K - 1)));
	}
	cout << ans << endl;
	return 0;
}

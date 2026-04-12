#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int iinf = 1 << 29;
const int imax = ~(1 << 31);
const long long linf = 1ll << 61;
const long long lmax = ~(1ll << 63);

#define dump(x) cerr << #x << " : " << x << '\n'
#define MOD(x, y) (((y) + (x) % (y)) % (y))

int main(int argc, char* argv[])
{
	int N, K;
	scanf("%d%d", &N, &K);
	ll ans = 0;
	for (int b = K + 1; b <= N; b++) {
		ll n = N / b;
		ll i = (ll)n * ll(b - K);
		if (N % b >= K) {
			i += N - n * (ll)b - K + 1;
		}
		if (K == 0) {
			i--;
		}
		ans += i;
	}
	printf("%lld\n", ans);

	return 0;
}

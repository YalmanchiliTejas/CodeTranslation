// #include C/C++ {
#include <bits/stdc++.h>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
// }

// #parameter{
#ifdef _DEBUG

#define TYPE decltype
#define RF(filename) {freopen((filename), "r", stdin);}
#define WF(filename) {freopen((filename), "w", stdout);}
#define DF(filename) {freopen((filename), "w", stderr);}
#define eprintf printf

#else

#define TYPE __typeof
#define RF(filename) {;}
#define WF(filename) {;}
#define DF(filename) {;}
#define eprintf(...)
#define fprintf(...)

#endif

// #define {
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define MP make_pair
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALL(it) (it).begin(), (it).end()
#define FILL(__space, __val) memset(__space, __val, sizeof(__space))
#define MOVE(__spaceTo, __spaceFrom) memmove(__spaceTo, __spaceFrom, sizeof(__spaceTo))
#define UNIQUE(__vector) sort(ALL(__vector)), __vector.resize(unique(ALL(__vector)) - __vector.begin())
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-6;

#define MAX_N 100005
#define MAX_M 55
#define MOD (int)(1e9+7)
#define INF ((1 << 30) - 1)
#define BINF ((1LL << 62) - 1LL)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
int fast_pow(int a, int n) {
	int sum = 1;
	while (n > 0) {
		if (n & 1) sum = 1LL * sum * a % MOD;
		a = 1LL * a * a % MOD;
		n >>= 1;
	}
	return sum;
}
int fact(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) res = 1LL * res * i % MOD;
	return res;
}
/////////////////////////////////////////////////////////////
int main() {
	RF("input.txt");
	//  WF("output.txt");
	DF("err.txt");

	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int res = 0;
	int comb = 1LL * fact(N * M - 2) * fast_pow(fact(K - 2), MOD - 2) % MOD * fast_pow(fact(N * M - K), MOD - 2) % MOD;
	for (int d = 1; d < N; d++) {
		int ways = 1LL * d * M % MOD * M % MOD * (N - d) % MOD;
		res = (res + ways) % MOD;
	}
	for (int d = 1; d < M; d++) {
		int ways = 1LL * d * N % MOD * N % MOD * (M - d) % MOD;
		res = (res + ways) % MOD;
	}
	res = 1LL * res * comb % MOD;
	printf("%d\n", res);
	return 0;
}
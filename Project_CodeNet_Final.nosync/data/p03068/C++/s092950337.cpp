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
#ifdef DEBUG_MODE

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

#define MAX_N 1005
#define MAX_M 55
#define MOD (int)(1e9+7)
#define INF ((1 << 30) - 1)
#define BINF ((1LL << 62) - 1LL)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
char S[MAX_N];
/////////////////////////////////////////////////////////////
int main() {
	RF("input.txt");
	//  WF("output.txt");
	DF("err.txt");
	
	int N, K;
	scanf("%d %s %d", &N, S, &K);
	for (int i = 0; i < N; i++) if (S[i] != S[K - 1]) S[i] = '*';
	puts(S);
	return 0;
}
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

LL dp[1005][1005];
const int MAX = 1005;
LL fac[MAX], finv[MAX], inv[MAX];

void init() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

LL  ncr(int n, int k) {
	if (n < k)return 0;
	if (n < 0 || k < 0)return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

LL mod_pow(LL a, LL p) {
	LL ret = 1;
	LL tmp = a;
	while (p) {
		if (p & 1)ret = (ret * tmp) % MOD;
		p >>= 1;
		tmp = (tmp * tmp) % MOD;
	}
	return ret;
}

int main() {
	int n, a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	dp[a][0] = 1;
	init();
	FOR(i, a, b + 1) {
		REP(j, n+1) {
			if (dp[i][j] == 0)continue;
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
			if (j + c * i > n)continue;
			FOR(k, c, d + 1) {
				if (j + k * i > n)break;
				LL tmp = (fac[n - j] * finv[n - j - k * i]) % MOD;
				tmp = (tmp * mod_pow(finv[i], k)) % MOD;
				tmp = (tmp * finv[k]) % MOD;
				dp[i + 1][j + k * i] = (dp[i + 1][j + k * i] + dp[i][j]*tmp) % MOD;
			}
		}
	}
	cout << dp[b + 1][n] << endl;
	return 0;
}
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

const int N = 200005;
long long fact[N];
long long invfact[N];
long long inv[N];

void init() {
	fact[0] = fact[1] = 1;
	for (int i = 2; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
	inv[1] = 1;
	for (int i = 2; i < N; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	invfact[0] = invfact[1] = 1;
	for (int i = 2; i < N; i++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}

LL nCr(LL n, LL r) {
	if (n < r || r < 0)return 0;
	return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}

int main() {
	LL n, m, k;
	cin >> n >> m >> k;
	init();
	LL cc = nCr(m * n - 2, k - 2);
	LL x1 = (m * m) % MOD;
	LL x2 = ((n * (n - 1) * (n + 1)) / 6) % MOD;
	LL y1 = (n * n) % MOD;
	LL y2 = ((m * (m - 1) * (m + 1)) / 6) % MOD;
	cout << (((x1*x2 + y1*y2) % MOD) * cc)%MOD << endl;
	return 0;
}
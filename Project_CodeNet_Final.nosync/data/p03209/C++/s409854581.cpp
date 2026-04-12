
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <stdio.h>
#include <complex>
#include <cstdint>
#include <tuple>
#include <numeric>
#define M_PI       3.14159265358979323846
#ifdef LOCAL
#include <sys/types.h>
#include <sys/timeb.h>
#include <intrin.h> 
#include <thread>
#else
#include <sys/time.h>
#endif

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
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
#define MT make_tuple
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FILL(a, x) memset(a, x, sizeof(a))

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)

LL f(LL n, LL k) {
	if (k == 0)return 0LL;
	if (n == 0)return 1LL;
	LL x = (1LL << (n + 2)) - 3;
	LL y = (x - 3) / 2;
	if (k <= 1) return 0LL;
	if (k <= 1 + y) return f(n - 1, k-1);
	return (1LL<<n) + f(n - 1, k - y - 2);
}

int main(){
	LL n, k;
	cin >> n >> k;
	cout << f(n, k) << endl;
	return 0;
}

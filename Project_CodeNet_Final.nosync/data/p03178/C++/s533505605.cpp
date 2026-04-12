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

const int N  = 10005;
const int D = 101;
LL dp[2][N][D];

int main() {
	string str;
	int d;
	cin >> str >> d;
	int n = str.length();
	dp[0][0][0] = 1;
	REP(i, n) {
		REP(j, d){
			dp[0][i + 1][(j + str[i] - '0') % d] = (dp[0][i + 1][(j + str[i] - '0') % d] + dp[0][i][j])%MOD;
			REP(k, str[i] - '0')dp[1][i + 1][(j + k) % d] = (dp[1][i + 1][(j + k) % d] + dp[0][i][j])%MOD;
			REP(k, 10)dp[1][i + 1][(j + k) % d] = (dp[1][i + 1][(j + k) % d] + dp[1][i][j])%MOD;
		}
	}
	cout << (dp[0][n][0] + dp[1][n][0] -1+MOD)%MOD << endl;
	return 0;
}
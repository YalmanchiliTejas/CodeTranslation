
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>


using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTch(s,c) ((((s).find_first_of(c)) != std::string::npos)? 1 : 0)//cがあれば1 if(1)
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define loop(n) FOR(i,0,n)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

LL num[60];
LL p[60];

LL f(LL N, LL X) {
	if (N == 0) {
		
		if (X == 1) {
			return 1;
		}
		else {
			return 0;
		}
		
	}

	if (X == 1) {
		return 0;
	}
	else if (X <= num[N - 1] + 1) {
		return f(N - 1, X - 1);
	}
	else if (X == num[N - 1] + 2) {
		return p[N - 1] + 1;
	}
	else if (X <= num[N - 1] * 2 + 2) {
		return f(N - 1, X - (num[N - 1] + 2)) + p[N - 1] + 1;
	}
	else {
		return p[N - 1] * 2 + 1;
	}

}

int main() {
	
	int n; LL x; cin >> n >> x;

	p[0] = 1;
	num[0] = 1;

	for (int i = 1; i <60; i++) {
		p[i] = p[i - 1]*2+1;
		num[i] = num[i - 1]*2+3;
	}

	cout << f(n, x) << endl;

	return 0;
}
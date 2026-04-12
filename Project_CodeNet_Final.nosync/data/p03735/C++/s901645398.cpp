
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
#include <complex>
#include <cstdint>
#include <tuple>
#include <numeric>
#define M_PI       3.14159265358979323846


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

const int N = 200005;
LL x[N], y[N];

int main() {
	int n;
	scanf("%d", &n);
	REP(i, n)scanf("%lld%lld", &x[i], &y[i]);
	REP(i, n)if (x[i] > y[i])swap(x[i], y[i]);
	LL xmin = 1e9, xmax = 0, ymin = 1e9, ymax = 0;
	REP(i, n) {
		xmin = min(xmin, x[i]);
		xmax = max(xmax, x[i]);
		ymin = min(ymin, y[i]);
		ymax = max(ymax, y[i]);
	}
	LL ans = (xmax - xmin) * (ymax - ymin);
	vector<pair<LL, LL>> xy;
	multiset<LL> sb;
	LL d = ymax - xmin;
	REP(i, n) {
		if (x[i] == xmin) {
			sb.insert(y[i]);
		}
		else if (y[i] == ymax) {
			sb.insert(x[i]);
		}
		else {
			sb.insert(x[i]);
			xy.push_back(MP(x[i], y[i]));
		}
	}
	SORT(xy);
	int k = xy.size();
	REP(i, k + 1) {
		ans = min(ans, ((*(--sb.end())) - (*sb.begin())) * d);
		if (i == k)break;
		sb.erase(sb.find(xy[i].first));
		sb.insert(xy[i].second);
	}
	cout << ans << endl;
	return 0;
}
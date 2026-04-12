#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

int n, m;
vector<int> es[8];

bool ved[8];

int dfs(int v, int rem) {
	if (rem == 0) return 1;
	int res = 0;
	REP(i, es[v].size()) if (!ved[es[v][i]]) {
		ved[es[v][i]] = true;
		res += dfs(es[v][i], rem - 1);
		ved[es[v][i]] = false;
	}
	return res;
}

int main(int argc, char **argv) {
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		es[a].push_back(b);
		es[b].push_back(a);
	}
	CLEAR(ved);
	ved[0] = true;
	cout << dfs(0, n - 1) << endl;
	return 0;
}

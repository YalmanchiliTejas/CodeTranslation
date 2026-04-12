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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(v) reverse((v).begin(),(v).end())
#define ANS(ans) cout<<(ans)<<endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)
long long a[51], pathi[51], ban[51];
long long count_pathi(int n, long long x) {
	if (n == 0) {
		return 1;
	}
	if (x == 1) {
		return 0;
	}
	else if (x <= 1 + a[n - 1]) {
		return count_pathi(n - 1, x - 1);
	}
	else if (x == a[n - 1] + 2) {
		return pathi[n - 1] + 1;
	}
	else if (x <= 2 * a[n - 1] + 2) {
		return count_pathi(n - 1, x - a[n - 1] - 2) + pathi[n - 1] + 1;
	}
	else {
		return pathi[n];
	}
}
int main() {

	long long n, x;
	cin >> n >> x;

	a[0] = 1;
	pathi[0] = 1;
	ban[0] = 0;
	FOR(i, 1, 50) {
		a[i] = a[i - 1] * 2 + 3;
		pathi[i] = pathi[i - 1] * 2 + 1;
		ban[i] = ban[i - 1] * 2 + 2;
	}

	long long ans= count_pathi(n, x);
	ANS(ans);

	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<iterator>
#include<complex>
#include<stack>
#include "stdio.h"
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const long long mod_const = 1e9+7;
using MIte = multimap<long, long, greater<long> >::iterator;

void Lower(ll idx, ll Level, ll& total) {
	ll nelem = pow(2, Level + 2) - 3;
	ll next_nelem = (nelem - 3) / 2;
	ll nP = pow(2, Level) - 1;

	ll nextidx = 0;
	if (idx > next_nelem + 2 && idx < nelem) {
		total += nP + 1;
		nextidx = idx - next_nelem - 2;
		Lower(nextidx, Level - 1, total);
	}
	else if (idx < next_nelem + 2 && idx > 1) {
		nextidx = idx-1;
		Lower(nextidx, Level - 1, total);
	}
	else if (idx == nelem) {
		total += 2 * nP + 1; // pow(2, Level + 1) - 1;
	}
	else if (idx == next_nelem + 2) {
		total += nP + 1;
	}
	else if (idx == 1) {
		if (Level == 0) {
			total += 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// long long?
	ll N, X;
	cin >> N >> X;

	ll total = 0;
	Lower(X, N, total);

	cout << total << endl;

	return 0;

}
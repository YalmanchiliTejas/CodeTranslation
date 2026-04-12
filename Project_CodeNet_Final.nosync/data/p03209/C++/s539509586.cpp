#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

ll numLevels[51];
ll numInside[51];

ll solve(int level, ll amt) {
	if(level == 0) {
		assert(amt == 1);
		return 1;
	}
	amt--;
	ll ret = 0;
	if(amt == 0) return 0;
	if(amt <= numLevels[level-1]) return solve(level-1, amt);
	ret += numInside[level-1];
	amt -= numLevels[level-1];
	if(amt == 0) return ret;
	ret++;
	amt--;
	if(amt == 0) return ret;
	if(amt <= numLevels[level-1]) return ret + solve(level-1, amt);
	return ret + numInside[level-1];
}

void solve() {
	numLevels[0] = 1;
	numInside[0] = 1;
	for(int i = 1; i <= 50; i++) {
		numLevels[i] = 2 * numLevels[i-1] + 3;
		numInside[i] = 2 * numInside[i-1] + 1;
	}
	int n;
	ll amt;
	cin >> n >> amt;
	cout << solve(n, amt) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
	/*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
	*/
	solve();
}

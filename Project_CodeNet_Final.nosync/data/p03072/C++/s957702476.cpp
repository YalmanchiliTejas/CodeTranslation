#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int n;
	cin >> n;
	
	vector<int> h(n);
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	
	int ans = 1;
	int maxH = h[0];
	for(int i = 1; i < n; ++i) {
		if( h[0] <= h[i] && maxH <= h[i] ) { 
			ans++;
			maxH = h[i];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

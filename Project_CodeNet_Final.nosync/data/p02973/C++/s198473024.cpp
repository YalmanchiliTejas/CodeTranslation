#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>
#include <map>
#include <bitset>
#include <functional>
#include <cmath>

#define INF 1000000010
using namespace std;

int dp[100010];
int n;
vector<int> a;

void solve() {
    fill(dp, dp+n, INF);
    for (int i=0; i<n; ++i) {
        *upper_bound(dp, dp+n, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp+n, INF) - dp << endl;
}


int main() {
	cin >> n;

	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		a.push_back(v);
	}
	reverse(a.begin(), a.end());

	solve();
}

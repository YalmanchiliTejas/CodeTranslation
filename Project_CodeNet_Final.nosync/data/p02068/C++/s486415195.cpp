#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int n;
int a[1000];

signed main() {
	int i, j;
	
	cin >> n;
	rep(i, n) cin >> a[i];
	
	vector<int> vec;
	rep(i, n) {
		for (j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				vec.push_back(j);
				if (j != a[i] / j) vec.push_back(a[i] / j);
			}
		}
	}
	
	int ans = 0;
	rep(i, vec.size()) {
		int k = vec[i];
		if (k <= 1) continue;
		
		int ssum = 0;
		rep(j, n) {
			if (a[j] % k == 0) ssum += a[j];
		}
		ans = max(ans, ssum);
	}
	cout << ans << endl;
	return 0;
}

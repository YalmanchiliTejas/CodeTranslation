#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 1;
	for (int i = 1; i < n; i++) {
		ans += a[i] >= a[i - 1];
		a[i] = max(a[i], a[i - 1]);
	}
	cout << ans << endl;
	return 0;
}

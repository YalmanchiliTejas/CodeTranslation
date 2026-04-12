#include <iostream>
#include <map>
#define int long long
using namespace std;

int n;
int a[200001];

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i + 1];
	for (i = 0; i < n; i++) a[i + 1] += a[i];
	
	map<int, int> dict;
	int ans = 0;
	for (i = n; i >= 0; i--) {
		if (dict.find(a[i]) != dict.end()) ans = max(ans, dict[a[i]] - i);
		if (dict.find(a[i]) == dict.end()) dict[a[i]] = i;
	}
	cout << ans << endl;
	return 0;
}
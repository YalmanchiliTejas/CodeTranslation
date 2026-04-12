#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int ans = 1e9;
	for (int i = 0; i <= 100000; i++) {
		ans = min(i * 2 * c + max(0, x - i) * a + max(0, y - i) * b, ans);
	}
	cout << ans << endl;
	return 0;
}
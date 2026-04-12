#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int x, y, z; cin >> x >> y >> z;

	int ans = 0;
	for (int i = 1; ; i++) {
		if (y * i + z * (i + 1) <= x)ans = max(ans, i);
		else break;
	}
	cout << ans << endl;

	return 0;
}
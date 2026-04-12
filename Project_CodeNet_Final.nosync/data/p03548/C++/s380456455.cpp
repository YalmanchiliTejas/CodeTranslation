#include <iostream>
using namespace std;

int main() {
	int x, y , z;
	cin >> x >> y >> z;

	int ans = 0;
	int i = z;
	while (i <= x) {
		i += y+z;
		ans++;
	}
	ans--;

	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans = 1;
	x -= y + 2 * z;
	ans += x / (y + z);
	cout << ans << endl;
}
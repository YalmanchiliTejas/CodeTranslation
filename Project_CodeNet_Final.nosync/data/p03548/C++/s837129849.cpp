#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;

	int result = 0;

	x -= z;

	while (x >= y + z) {
		x -= y + z;
		result++;
	}

	cout << result << endl;
}

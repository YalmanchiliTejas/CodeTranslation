#include"bits/stdc++.h"

using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int ans = 0;

	for (int i = 0; i < 1000000; i++) {
		if (Y*i + Z*(i + 1) <= X) {
			ans = i;
		}
		else {
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int x = A * 100 + 10 * B + C;
	if (0 == x % 4) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
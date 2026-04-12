#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n = 0, t;
	for (int i = 0; i < 3; i++) {
		cin >> t;
		n += t;
		n *= 10;
	}
	n /= 10;
	if (n % 4) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}

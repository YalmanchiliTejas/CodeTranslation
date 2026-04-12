#include <iostream>
using namespace std;

long long Ceil(long long a, long long b) {
	return (a + b - 1) / b;
}

int main() {
	long long k, a, b;
	cin >> k >> a >> b;
	
	if (a > b) {
		cout << 2 * Ceil(k - b, a - b) - 1 << endl;
	}
	else {
		if (a >= k) { cout << 1 << endl; }
		else { cout << -1 << endl; }
	}
	return 0;
}
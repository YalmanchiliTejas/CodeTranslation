#include <iostream>

using namespace std;

int main() {

	long long int k, a, b;
	cin >> k >> a >> b;

	if (a - b > 0) {
		long long int p = k - a;
		long long int aa, bb;
		aa = bb = p / (a - b);
		while (aa*a - bb*b < k) {
			if ((aa + 1)*a - bb*b >= k) {
				aa++;
				break;
			}
			else {
				aa++;
				bb++;
			}
		}
		cout << aa + bb << endl;
	}
	else {
		if (a >= k) {
			cout << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}
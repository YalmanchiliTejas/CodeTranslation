#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
long long K, A, B;
int main() {
	cin >> K >> A >> B;
	if (A >= K) cout << 1 << endl;
	else {
		if (A > B) {
			long long p = K - A;
			long long q = A - B;
			cout << (p + q - 1) / q * 2 + 1 << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
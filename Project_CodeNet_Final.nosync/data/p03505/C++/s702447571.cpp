#include "bits/stdc++.h"
using namespace std;

int main() {
	long long K, A, B;
	cin >> K >> A >> B;
	if (K <= A) {
		cout << 1 << endl;
		return 0;
	}
	if (A <= B) {
		cout << -1 << endl;
		return 0;
	}
	cout << ((K - A - 1) / (A - B)) * 2 + 3 << endl;
}
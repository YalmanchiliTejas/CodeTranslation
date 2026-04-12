#include<iostream>
using namespace std;
int a, b, x[1000], y[1000], p, sum, ok; char c;
int main() {
	while (cin >> a >> c >> b) {
		if (a + b == 0) { break; }
		x[a] = b; p++;
	}
	sum = 1;
	for (int i = 30; i >= 0; i--) {
		ok = 0;
		for (int j = 1; j <= p; j++) {
			if (x[j] == i) { y[j] = sum; ok = 1; }
		}
		if (ok) { sum++; }
	}
	while (cin >> a) {
		cout << y[a] << endl;
	}
}
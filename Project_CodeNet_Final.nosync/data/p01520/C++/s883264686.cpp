#include<iostream>
using namespace std;
int x[10000000];
int a, n, m, c;
int main() {
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j < 10000000; j += a) {
			x[j] = i;
		}
	}
	for (int i = m - c; i <= m + c; i++) {
		if (x[i] >= 1) { cout << x[i] << endl; goto E; }
	}
	cout << "-1" << endl;
E:;
	return 0;
}
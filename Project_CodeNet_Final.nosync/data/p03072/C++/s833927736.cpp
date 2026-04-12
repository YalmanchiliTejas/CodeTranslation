#include<iostream>
#include<string>
using namespace std;
int main() {
	int n, h[20], a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int j = 0; j < n; j++) {
		a = 0;
		for (int k = 0; k < j; k++) {
			if (h[j] >= h[k]) {
				a++;
			}
		}
		if (a == j) {
			b++;
		}
	}
	cout << b << endl;
	return 0;
}

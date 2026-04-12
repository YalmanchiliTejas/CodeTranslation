#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int max = h[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (max <= h[i]) {
			max = h[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
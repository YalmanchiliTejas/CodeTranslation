#include <iostream>
using namespace std;

int main() {
	int n, h[21], max[21];
	int ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		
	}

	for (int i = 0; i < n; i++) {
		if (i == 0)max[i] = h[i];
		else {
			if (h[i] < max[i - 1]) max[i] = max[i - 1];
			else max[i] = h[i];
		}

	}
	cout << endl;
	for (int i = 1; i < n; i++) {
		if (h[i] >= max[i]) ans++;
	}
	cout << ans << endl;


	return 0;
}
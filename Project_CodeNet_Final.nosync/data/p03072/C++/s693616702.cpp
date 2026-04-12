#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    
	int n;
	int h[20];
	int max = 0;
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for (int i = 0; i < n; i++) {
		if (h[i] >= max) {
			ans++;
			max = h[i];
		}
	}

	cout << ans << endl;

	return 0;
}
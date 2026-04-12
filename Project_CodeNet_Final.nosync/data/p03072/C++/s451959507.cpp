#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int h[20];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	int max[20];
	max[0] = h[0];
	int highest = h[0];
	for (int i = 1; i < n; i++) {
		if (highest < h[i])
			highest = h[i];
		max[i] = highest;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (max[i] == h[i])
			ans++;
	cout << ans << endl;
	return 0;
}
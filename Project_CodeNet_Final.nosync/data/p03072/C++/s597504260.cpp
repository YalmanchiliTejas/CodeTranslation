#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n; 
	vector<int>h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	int ans = 1;
	int border = h[0];
	for (int i = 1; i < n; i++) {
		int maxi = h[i];
		for (int j = i - 1; j >= 0; j--) {
			maxi = max(maxi, h[j]);
		}
		if (maxi == h[i]) ans++;
	}
	cout << ans << endl;

	return 0;
}
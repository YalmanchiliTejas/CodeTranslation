#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vi;

int main() {
	int n;
	cin >> n;

	vi h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	
	int ans = 0;
	int max_height = -1;

	for (int i = 0; i < n; i++) {
		if (max_height <= h[i]) {
			ans += 1;
			max_height = h[i];
		}

	}
	cout << ans << endl;	
}
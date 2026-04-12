#include "bits/stdc++.h"


using namespace std;

int main() {
	//input
	int n; cin >> n;
	vector<int> H(n);

	for (int i = 0;i < n;i++) {
		
		cin >> H[i];
		
	}

	//compute
	int ans = 0;
	int max = 0;
	for (int i = 0;i < n;i++) {
		if (max <= H[i]) {
			max = H[i];
			ans++;
		}
	}

	//output
	cout << ans << endl;


}
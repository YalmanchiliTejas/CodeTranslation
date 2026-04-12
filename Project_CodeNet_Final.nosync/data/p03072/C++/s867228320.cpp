#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int main() {
	int N; cin >> N;
	vector<int> H;

	int ans = 0;
	int max = -1;
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		H.push_back(t);
		if (H[i] >= max) {
			ans++;
			max = H[i];
		}
	}
	
	cout << ans << endl;


	return 0;
}
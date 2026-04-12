#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, t, e;
	cin >> n >> t >> e;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for(int j = -e; j <= e; j++){
			if ((t + j) % x[i] == 0) {
				ans = i + 1;
				break;
			}
		}
		if (ans != -1) break;
	}

	cout << ans << endl;
}

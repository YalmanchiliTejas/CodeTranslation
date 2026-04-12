#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int m = h[0], count= 1;
	for (int i = 1; i < n; i++) {
		if (m <= h[i]) {
			count++;
			m = max(m, h[i]);
		}
	}

	cout << count << endl;

	return 0;
}
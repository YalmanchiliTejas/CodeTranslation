#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int ans = 0;

	int  N;
	vector<int> h;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int j;
		cin >> j;
		h.push_back(j);
	}
	int th =0;

	for (int i = 0; i < N; i++) {
		if (h[i] >= th) {
			th = h[i];
			ans++;
		}
	}
	
	cout << ans;
}
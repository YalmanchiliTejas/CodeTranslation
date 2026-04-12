#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end());
	vector<int> ans(n);
	for (int i = 0; i < n / 2; ++i) {
		ans[arr[i].second] = arr[n / 2].first;
	}
	for (int i = n / 2; i < n; ++i) {
		ans[arr[i].second] = arr[n / 2 - 1].first;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << '\n';
	}
}
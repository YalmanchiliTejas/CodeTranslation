#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <pair<int, int> > ar(n);
	for (int i = 0; i < n; ++i) {
		cin >> ar[i].first;
		ar[i].second = i;
	}
	vector <int> ans(n);
	sort(ar.begin(), ar.end());
	for (int i = 0; 2 * i < n; ++i) {
		ans[ar[i].second] = ar[n / 2].first;
	}
	for (int i = n / 2; i < n; ++i) {
		ans[ar[i].second] = ar[n / 2 - 1].first;
	}
	for (int it: ans) {
		cout << it << endl;
	}
}
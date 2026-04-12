#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int> input(n);
	for (int i = 0; i < n; ++i) cin >> input[i];
	auto cp = input;
	sort(cp.begin(), cp.end());

	int B = cp[n / 2 - 1], B1 = cp[n / 2];
	for (int i = 0; i < n; ++i) cout << ((input[i] > B) ? B : B1) << endl;

	return 0;
}
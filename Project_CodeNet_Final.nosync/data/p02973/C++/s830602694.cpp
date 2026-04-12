#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> d;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		auto it = upper_bound(d.begin(), d.end(), a, greater<>());
		if (it == d.end()) d.push_back(a);
		else *it = a;
	}
	cout << d.size() << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	set <pair<int, int>> s;
	int c = 0;
	for (int i = 0; i < n; i++) {
		auto it = s.upper_bound({-a[i], n}); 
		if (it == s.end()) {
			c++;
			s.emplace(-a[i], c);
		}
		else {
			int color = it->second;
			s.erase(it);
			s.emplace(-a[i], color);
		} 
	}
	cout << c;
	return 0;
}

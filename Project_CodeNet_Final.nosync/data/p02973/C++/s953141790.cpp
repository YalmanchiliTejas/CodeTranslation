#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	multiset<int, greater<int>> ms;
	for(int i=0; i<n; i++) {
		auto it = ms.upper_bound(a[i]);
		if(it != ms.end())
			ms.erase(it);
		ms.insert(a[i]);
	}
	cout << ms.size();
}
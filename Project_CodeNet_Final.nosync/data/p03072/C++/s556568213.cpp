#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;

int main() { 
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int cnt = 1;
	int p = v[0];
	for (int i = 1; i < n; ++i) {
		p = max(p,v[i]);
		if (p == v[i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0; 
} 


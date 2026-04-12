#include<bits/stdc++.h>
using namespace std;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	x -> n - 1 - x -> n+1 - (n-1-x) 
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> a[2];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = n-1; i >= 0;i --) {
		if ((n - 1 - i) % 2 == 0) {
			a[0].push_back(v[i]);
		}
		else a[1].push_back(v[i]);
	}
	reverse(a[1].begin(),a[1].end());
	for (int j = 0;j < 2; j++)
	for (int i : a[j]) {
		cout << i <<' ';
	}
	
}
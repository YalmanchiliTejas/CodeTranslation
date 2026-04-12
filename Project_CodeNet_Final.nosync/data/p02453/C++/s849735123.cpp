#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i){
		int k;
		cin >> k;
		
		auto it = lower_bound(v.begin(), v.end(), k);
		cout << distance(v.begin(), it) << endl;
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n), ops;
	for(int & v : a) cin >> v;
	auto sorted = [&](){
		for(int k = 0; k < n; k++){
			int i;
			for(i = 0; i < n - 1; i++) if(a[(i + k) % n] > a[(i + 1 + k) % n]) break;
			if(i == n - 1) return k;
		}
		return -1;
	};
	auto op = [&](int k){
		ops.push_back(k);
		for(int i = k; i < n; i++)
			swap(a[i], a[i - k]);
	};
	for(int i = 0; i < n && sorted() == -1; i++){
		for(int j = 0; j < n - 1; j++){
			op(1);
			if(a[0] < a[n - 1]) op(n - 1);
		}
		op(1);
	}
	while(sorted() != 0) op(1);
	cout << ops.size() << '\n';
	for(int v : ops) cout << v << '\n';
	return 0;
}

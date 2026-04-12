//besmellah
#include <bits/stdc++.h>
using namespace std;
// __builtin_popcount

// vector <int> h;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// h.resize(n);
	int ans = 0, Q = 0;
	for (int i = 0; i < n; i++){
		int h;
		cin >> h;
		if (h >= Q){
			ans ++;
			Q = h;
		}
	}
	cout << ans;
}
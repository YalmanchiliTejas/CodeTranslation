#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; cin >> n; std::vector<int> vec(n);
	for(int i = 0; i < n; i++) cin >> vec[i];
	sort(begin(vec), end(vec));
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(vec.back() % vec[i] == 0) continue;
		int mi = 1 << 30;
		for(int j = 1; j * j <= vec.back(); j++) {
			if(vec.back() % j) continue;
			if(j > vec[i]) mi = std::min(mi, j - vec[i]);
			if(vec.back() / j > vec[i]) mi = std::min(mi, vec.back() / j - vec[i]);
		}
		ans += mi;
	}
	
	cout << ans << endl;
	return 0;
}


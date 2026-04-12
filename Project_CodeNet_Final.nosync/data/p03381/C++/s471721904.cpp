#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; scanf("%d", &n); std::vector<std::pair<int, int>> a;
	for(int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		
		a.push_back({x, i});
	}
	sort(begin(a), end(a));
	
	int L = n / 2, A = a[L - 1].first, B = a[L].first;
	std::vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		if(i < L) ans[a[i].second] = B;
		else ans[a[i].second] = A;
	}
	for(auto v : ans) printf("%d\n", v);
	return 0;
}

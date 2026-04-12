#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
const int N = 200005;

int n, a[N];

bool f(int k) {
	multiset<int> s;
	for(int i = 0; i < k; i++) s.insert(-1);
	for(int i = 1; i <= n; i++) {
		auto it = s.lower_bound(a[i]);
		if(it == s.begin()) return false;
		it--;
		s.erase(it);
		s.insert(a[i]);
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	int lo = 1, hi = n - 1, ans = n;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(f(mid)) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	printf("%d\n", ans);
}

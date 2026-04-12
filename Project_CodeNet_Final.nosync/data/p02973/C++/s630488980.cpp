#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	reverse(a.begin(), a.end());
	vector<int> lis(n+1, INT_MAX);
	int ans = 1;
	lis[0] = -1;
	for(int i = 0; i < n; i++) {
		int x = a[i];
		
		int lo = 0, hi = n-1;
		while(lo < hi) {
			int mid = lo + (hi - lo + 1)/2;
			if(lis[mid] <= x) {
				lo = mid;
			} else {
				hi = mid-1;
			}
		}
		lis[lo+1] = min(lis[lo+1], x);
		ans = max(ans, lo+1);
	}
	
	cout << ans << endl;
}

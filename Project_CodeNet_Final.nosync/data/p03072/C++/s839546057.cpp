#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int a[N] = { 0 };

int main() {
	int n, ans = 0, highest = 0;
	cin >> n;
	for(int i(0);i < n;++i) {
		cin >> a[i];
		highest = max(a[i], highest);
		a[i] -= highest;
	}
	for(int i(0);i < n;++i){
		if(a[i] >= 0) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}

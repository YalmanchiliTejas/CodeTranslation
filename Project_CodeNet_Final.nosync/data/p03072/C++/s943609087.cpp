#include <bits/stdc++.h>
using namespace std;

int f[110], a[110], ans = 0;

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int now = 0;
	for(int i = 1; i <= n; ++i) {
		if(now <= a[i]) ++ans;
		now = max(now, a[i]);
	}
	cout << ans;
}
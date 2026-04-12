#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, a[30], mx[30], ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mx[0] = a[0];
	for (int i = 1; i < n; i++)
		mx[i] = max(a[i], mx[i - 1]);
	for (int i = 1; i < n; i++)
		if (a[i] >= mx[i - 1])
			ans++;
	cout << ans;
}






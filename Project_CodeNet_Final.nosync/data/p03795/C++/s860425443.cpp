#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, x, ans;
	cin >> n;
	x = n / 15;
	ans = 800 * n - 200 * x;
	cout << ans << endl;

	return 0;
}
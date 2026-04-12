#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<climits>

using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int b = k + 1; b <= n; b++) {
		ans += (n / b)*(b - k) + max(0, (n%b) - k + 1);
	}
	if (k == 0) ans -= n;
	cout << ans << endl;
	return 0;
}
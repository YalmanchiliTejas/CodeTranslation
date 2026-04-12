#include <iostream>
using namespace std;
typedef long long ll;
ll n, k, ans;
int main() {
	cin >> n >> k;
	if (k == 0)ans = n * n;
	else for (int i = k + 1; i <= n; i++)ans += n / i * (i - k) + (n - n / i * i >= k ? n - n / i * i - k + 1 : 0);
	cout << ans << endl;
	return 0;
}
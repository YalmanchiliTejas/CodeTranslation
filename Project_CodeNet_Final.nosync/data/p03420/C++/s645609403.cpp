#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	long long n, k;
	cin >> n >> k;
	long long cnt = 0;
	for(long long i = 1; i <= n; i++) {
		long long p = n / i;
		long long r = n % i;
		cnt += p * max(0LL, i - k) + max(0LL, r - k + 1);
		cnt -= k == 0;
	}
	cout << cnt << endl;
	return 0;
}
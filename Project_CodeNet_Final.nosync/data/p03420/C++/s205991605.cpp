#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for(int i = k+1; i <= n; i++) {
		ans += 1LL * (n / i) * (i - k);
		if(n % i != 0) {
			if((n % i) >= k) {
				ans += (n % i) - k + 1;
				if(k == 0) ans--;
				// cout << i << " " << (n % i) - k + 1 << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
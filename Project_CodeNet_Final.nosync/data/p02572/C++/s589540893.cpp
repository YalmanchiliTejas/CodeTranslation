/**
 *    author:  yoseph
 *    created: 09.09.2020 19:42:20      
**/
#include <bits/stdc++.h>
using namespace std;

const long M = 1000000007;

#if 0
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = (ans % M + (v[i] % M * v[j] % M) % M) % M;
		}
	}
	cout << ans << "\n";

	return 0;
}
#endif

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long sum =0;
	vector<int> A(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		sum += A[i];
		sum %= M;
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		sum -= A[i];
		if (sum < 0)
			sum += M;
		ans += A[i] * sum;
		ans %= M;
	}
	cout << ans << "\n";
	return 0;
}

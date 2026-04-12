#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
using namespace std;

using ll = long long;
int main() {
	int n;
	cin >> n;
	vector<ll> A(n);
	ll high = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		high += A[i];
	}
	ll low = -1;
	while (high - low > 1) {
		ll H = high;
		ll mean = (low + high) / 2;
		for (ll M = max(low, mean - n); M <= mean; M++) {
			vector<ll> B(A);
			for (int i = 0; i < n; i++) {
				B[i] += M;
			}
			ll k = 0;
			for (int i = 0; i < n; i++) {
				if (B[i] > n - 1) {
					k += (B[i] - n + 1) / (n + 1);
					if ((B[i] - n + 1) % (n + 1) != 0) {
						k++;
					}
				}
			}
			if (k <= M) {
				high = M;
				break;
			}
		}
		if (high == H) {
			low = mean;
		}
	}
	cout << high <<endl;
}

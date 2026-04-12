#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const LL MOD = 1000000007LL;
LL a[50];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	LL ans = 0;
	while (1) {
		LL sum = 0;
		for (int i = 0; i < N; i++) sum += a[i] / N;
		if (sum == 0) break;
		ans += sum;
		for (int i = 0; i < N; i++) {
			LL q = a[i] / N;
			a[i] += sum - q;
			a[i] -= q*N;
		}
	}
	cout << ans << endl;
}
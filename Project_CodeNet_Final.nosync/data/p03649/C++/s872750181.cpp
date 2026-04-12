#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
const LL MOD = 1000000007LL;

int main() {
	int N;
	cin >> N;
	LL a[50];
	for (int i = 0; i < N; i++) cin >> a[i];
	LL ans = 0;
	while (1) {
		LL sum = 0;
		for (int i = 0; i < N; i++) sum += a[i] / N;
		if (sum == 0) break;
		for (int i = 0; i < N; i++) {
			LL d = a[i] / N;
			a[i] -= d*N;
			a[i] += sum - d;
		}
		ans += sum;
	}
	cout << ans << endl;
}
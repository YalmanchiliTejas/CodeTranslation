#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const double EPS = 1e-10;
ll A[100000];
int p[100000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	for (int i = 0; i + 1 < N; i++) {
		if (i % 2 == 0) {
			p[i]++;
			p[i + 1]--;
		}
		else {
			p[i]--;
			p[i + 1]++;
		}
	}
	sort(p, p + N);
	ll ans = 0;
	ll sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum += A[i] * p[i];
	}
	ans = sum;
	sum = 0;
	memset(p, 0, sizeof(p));
	for (int i = 0; i + 1 < N; i++) {
		if (i % 2 == 0) {
			p[i]--;
			p[i + 1]++;
		}
		else {
			p[i]++;
			p[i + 1]--;
		}
	}
	sort(p, p + N);
	for (int i = N - 1; i >= 0; i--) {
		sum += A[i] * p[i];
	}
	ans = max(ans, sum);
	cout << ans << endl;
}
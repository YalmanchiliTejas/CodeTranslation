// ABC177C - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

#define MOD 1000000007

int main() {
	int N;
	cin >> N;
	ull A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	ull sum = 0;
	ull psum[N];

	for (int i = 0; i < N; i++) {
		sum += A[i];
		sum %= MOD;
		psum[i] = sum;
	}

	sum %= MOD;

	ull ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ull temp = 0;
		if (sum > psum[i]) {
			temp = (sum - psum[i])% MOD;
		} else {
			temp = (sum - psum[i] + MOD)% MOD;
		}
		ans += (A[i] * temp)% MOD;
	}

	ans %= MOD;
	cout << ans << endl;

	return 0;
}

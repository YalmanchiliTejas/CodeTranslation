// copied from https://atcoder.jp/contests/abc177/submissions/16358885

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int A[N];
	ll B[N+1];
	int mod = 1000000007;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i + 1] = B[i] + A[i];
	}

	long ans = 0;

	//i について全探索する
	for (int i = 0; i < N; i++) {
		//累積和を使ってA[i+1] + ... + A[N] を求める
		long long sum = (B[N] - B[i + 1]) % mod;

		ans += A[i] * sum;
		ans %= mod;
	}

	cout << ans << endl;
    return 0;
}


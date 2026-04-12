#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<long long> B(N + 1, 0); //累積和テーブル
	int mod = 1000000007;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i + 1] = B[i] + A[i];
	}

	long ans = 0;

	//i について全探索する
	for (int i = 0; i < N; i++)
	{
		//累積和を使ってA[i+1] + ... + A[N] を求める
		long long sum = (B[N] - B[i + 1]) % mod;

		ans += (A[i]%mod) * sum;
		ans %= mod;
	}

	cout << ans << endl;
}
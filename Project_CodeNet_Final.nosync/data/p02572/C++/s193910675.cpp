#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	long long sum = 0;
	int mod = 1000000007;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		sum += A[i];
		sum %= mod;
	}

	//大きい正方形の面積を求める
	long long ans = sum * sum % mod;
	//中央の正方形を取り除く
	for (int i = 0; i < N; i++)
	{
		ans -= (long long)A[i] * A[i] % mod;
		if (ans < 0) ans += mod;
	}

	//2で割る (逆元を用いる)
	//ans /= 2 を mod 1000000007で行うとこうなる
	ans *= (mod + 1) / 2;
	ans %= mod;

	cout << ans << endl;
}


#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

int addm(int a, int b)
{
	return (0LL + a + b) % MOD;
}

int subm(int a, int b)
{
	return addm(a, (MOD - b) % MOD);
}

int mulm(int a, int b)
{
	return (1LL * a * b) % MOD;
}

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& x : A) {
		cin >> x;
	}

	vector<int> acc(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		acc[i + 1] = addm(acc[i], A[i]);
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans = addm(ans, mulm(A[i], subm(acc[N], acc[i + 1])));
	}
	cout << ans << endl;
}

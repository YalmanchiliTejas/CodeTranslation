#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <functional>

#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<long long> A(N, 0);
	vector<long long> accumlist(N + 1, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		accumlist[i + 1] = accumlist[i] + A[i];
	}

	long long result = 0;
	for (int i = 0; i < N - 1; i++)
	{
		long long value = (accumlist[N] - accumlist[i + 1]) % MOD;
		value = (value * A[i]) % MOD;

		result = (result + value) % MOD;
	}

	cout << result;

	return 0;
}

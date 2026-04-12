#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cctype>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

const int mod = 1000000007;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ll long long

int main()
{
    int N;
	cin >> N;

	vector<int> A(N);
	vector<ll> B(N + 1, 0);
	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i + 1] = B[i] + A[i];
	}

	ll ans = 0;
	for (size_t i = 0; i < N; i++)
	{
		ll sum = (B[N] - B[i + 1]) % mod;
		ans += A[i] * sum;
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}
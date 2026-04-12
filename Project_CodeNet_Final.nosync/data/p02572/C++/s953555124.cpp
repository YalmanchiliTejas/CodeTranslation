#include <iostream>
#include <algorithm>
using namespace std;

long long n, m = 0, w = 0, k = 1, v = 2;
long long a[200000];
const long long M = 1e9 + 7;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		m = (m + a[i]) % M;
		w = (w + (a[i] * a[i] % M)) % M;
	}

	m = m * m % M;
	m = (m + M - w) % M;

	for (int i = 0; (1ull << i) < M; i++) {
		if ((1ull << i) & M - 2)
			k = k * v % M;

		v = v * v % M;
	}

	cout << m * k % M << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MOD;

int addm(int a, int b)
{
	return (0LL + a + b) % MOD;
}

int mulm(int a, int b)
{
	return (1LL * a * b) % MOD;
}

int main()
{
	long long N;
	int X, M;
	cin >> N >> X >> M;
	MOD = M;

	vector<int> a;
	vector<bool> v(M, false);

	a.push_back(X);
	v[X] = true;
	int loop;
	for (;;) {
		int y = mulm(a.back(), a.back());
		if (v[y]) {
			loop = find(a.begin(), a.end(), y) - a.begin();
			break;
		}
		a.push_back(y);
		v[y] = true;
	}

	int length = a.size();
	int prefix = loop;
	int period = length - prefix;

	long long ans = 0;
	for (int i = 0; i < N && i < prefix; ++i) {
		ans += a[i];
	}
	if (N > prefix) {
		N -= prefix;
		auto q = N / period;
		auto r = N % period;

		long long sum = 0;
		for (int i = prefix; i < length; ++i) {
			sum += a[i];
		}
		ans += sum * q;
		for (int i = prefix; i < prefix + r; ++i) {
			ans += a[i];
		}
	}

	cout << ans << endl;
}


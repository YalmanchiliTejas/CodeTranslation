#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long comb(long long n, long long k)
{
	//cout << "comb(" << n << "," << k << ")" << endl;
	if (n < 0 || k < 0 || n < k) {
		return 0;
	}
	long long c = 1;
	for (long long i = 0; i < k; ++i) {
		c *= n - i;
	}
	for (long long i = 0; i < k; ++i) {
		c /= i + 1;
	}
	return c;
}

int main()
{
	string N;
	int K;
	cin >> N >> K;

	const int L = N.size();

	if (K > L) {
		cout << 0 << endl;
		return 0;
	}

	long long ans = 0;
	int p = 0;
	for (int i = 0; i < L; ++i) {
		//cout << "i=" << i << endl;
		if (N[i] == '0') {
			continue;
		} else {
			++p;
		}
		long long t = 1;
		for (int j = 0; j < K - p; ++j) {
			t *= 9;
		}
		for (int x = N[i] - '0' - 1; x > 0; --x) {
			ans += t * comb(L - 1 - i, K - p);
			//cout << "[1]" << t * comb(L - 1 - i, K - p) << endl;
		}

		int d = (N[i] == '0') ? 0 : +1;

		t = 1;
		for (int j = 0; j < K - p + d; ++j) {
			t *= 9;
		}
		ans += t * comb(L - 1 - i, K - p + d);
		//cout << "[2]" << t * comb(L - 1 - i, K - p + d) << endl;
	}
	
	if (count(N.begin(), N.end(), '0') == L - K) {
		++ans;
	}
	
	cout << ans << endl;
}
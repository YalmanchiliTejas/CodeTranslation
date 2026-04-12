#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	long long ans = 0;
	for (int i = max(1, K); i <= N; i++) {
		int last;
		for (int j = 1; j <= i; j = last+1) {
			last = i/(i/j);
			int R = (i-K)/(i/j);
			if (R >= j) {
				ans += min(R, last)-j+1;
				// cerr << i << " " << j << " " << R << " " << last << endl;
			}
		}
		ans += N-i;
	}
	cout << ans << endl;
	return 0;
}

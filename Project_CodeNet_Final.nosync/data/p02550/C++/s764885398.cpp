#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 998244353;

void solve_test() {
	LL n;
	int x, m;
	cin >> n >> x >> m;
	
	LL sum = 0;

	vector<int> marked(m, -1);
	vector<int> values;
	int t = x, i = 0;
	while (n > 0 && marked[t] == -1) {
		marked[t] = i;
		values.push_back(t);
		
		sum += t;

		t = (LL) t * t % m;
		i++;

		n--;
	}

	if (n == 0) {
		cout << sum << '\n';
		return;
	}

	int from = marked[t];
	int to = i;
	int length = to - from;

	for (int i = from; i < to; i++) {
		sum += (LL)(values[i]) * (n / length);
		if (i - from < n % length)
			sum += values[i];
	}

	cout << sum << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}

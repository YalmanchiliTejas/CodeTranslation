#include <bits/stdc++.h>

using namespace std;

long long N, X, M;
map <long long, int> values;
long long sums[4000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> X >> M;
	
	values[X] = 1;
	sums[1] = X;
	
	long long rep_beg, rep_end;
	long long rep_sum;
	for (int i = 2; ; i++) {
		X = (X * X) % M;
		
		if (values.count(X) != 0) {
			rep_beg = values[X];
			rep_end = i - 1;
			rep_sum = sums[rep_end] - sums[rep_beg - 1];
			break;
		}
		
		values[X] = i;
		sums[i] = sums[i - 1] + X;
	}
	
	long long ans;
	
	if (rep_beg > N) {
		ans = sums[N];
	} else {
		long long cycles = (N - rep_beg + 1) / (rep_end - rep_beg + 1);
		ans = 0;
		ans += rep_sum * cycles;
		ans += sums[N - cycles * (rep_end - rep_beg + 1)];
	}
	
	cout << ans << "\n";
	
	return 0;
}

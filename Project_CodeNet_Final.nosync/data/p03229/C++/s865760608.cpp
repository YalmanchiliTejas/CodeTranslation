#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N;
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<ll> sum(N + 1);
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + A[i];
	}
	int id = N / 2;
	ll res = ((sum[N] - sum[id]) - A[id] * (N - id) + A[id] * id - sum[id]) * 2;
	if (N & 1) res -= min(A[id + 1] - A[id], A[id] - A[id - 1]);
	else res -= A[id] - A[id - 1];
	cout << res << endl;
	return 0;
}

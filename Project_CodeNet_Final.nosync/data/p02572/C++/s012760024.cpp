#include"bits/stdc++.h"
using namespace std;
int MOD = 1000000007;
int main() {
	int N; cin >> N;
	vector<int> A(N);
	long long ans = 0, m = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A.at(i);
		m += A.at(i);
		m %= MOD;
	}
	for (int i = 0; i < N; i++)
	{
		m -= A.at(i);
		if (m < 0) m += MOD;
		ans += A.at(i) * m;
		ans %= MOD;
	}
	cout << ans << endl;
}
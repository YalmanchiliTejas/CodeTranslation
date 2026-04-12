#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> A(N);
	REP(i, N)
	cin >> A[i];
	SORT(A);
	vector<ll> B(N);
	B[N / 2] = A[0];
	int l = 1, r = N - 1;
	int i = N / 2, j = N / 2;
	while (true) {
		if (i - 1 >= 0) {
			--i;
			B[i] = A[r];
		}
		if (j + 1 == N) break;
		++j;
		B[j] = A[r - 1];
		r -= 2;
		if (i - 1 >= 0) {
			--i;
			B[i] = A[l];
		}
		if (j + 1 == N) break;
		++j;
		B[j] = A[l + 1];
		l += 2;
	}
	vector<ll> C(N);
	C[N / 2] = A[N - 1];
	l = 0, r = N - 2;
	i = j = N / 2;
	while (true) {
		if (i - 1 >= 0) {
			--i;
			C[i] = A[l];
		}
		if (j + 1 == N) break;
		++j;
		C[j] = A[l + 1];
		l += 2;
		if (i - 1 >= 0) {
			--i;
			C[i] = A[r];
		}
		if (j + 1 == N) break;
		++j;
		C[j] = A[r - 1];
		r -= 2;
	}
	ll b = 0, c = 0;
	REP(i, N - 1) {
		b += abs(B[i + 1] - B[i]);
		c += abs(C[i + 1] - C[i]);
	}
	cout << max(b, c) << endl;

	return 0;
}
#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define all(c) begin(c),end(c)
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
using ll = long long;
using vi = vector<int>; using vs = vector<string>;
int dd[] = { 0, 1, 0, -1, 0 }; //→↓←↑

void solve()
{
	int N;
	while (cin >> N, N) {
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int sum = 0;
		for (int i = 1; i < N - 1; i++) {
			sum += A[i];
		}
		sum /= (N - 2);
		cout << sum << endl;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;
constexpr ll INF = 1000000000;
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<int>x(n);
	vector<int>b(n);

	rep(i, n) {
		cin >> x[i];
		b[i] = x[i];
	}
	sort(b.begin(),b.end());

	vector<int>a(n);
	for (int i = 0; i < n; ++i) {
		if (x[i] <= b[n / 2 - 1]) {
			a[i] = b[n / 2];
		}
		else {
			a[i] = b[n / 2 - 1];
		}
	}
	rep(i, n)cout << a[i] << endl;
}
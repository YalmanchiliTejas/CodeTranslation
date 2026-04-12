#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		if (a[i] <= b[n / 2 - 1]) cout << b[n / 2] << endl;
		else cout << b[n / 2 - 1] << endl;
	}
	return 0;
}

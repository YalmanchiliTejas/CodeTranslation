#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
const ll inf = 1e17;
int n, a[N];
ll d[N], r[N], e[N], ma;

ll E(int n) {
	return e[n];
}

ll D(int n) {
	if(n == 1) return 0;
	else if(n & 1) return max(D(n - 2) + a[n], E(n - 1));
	else return E(n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 2; i <= n; i += 2) {
		d[i] = d[i - 2] + a[i - 1];
		r[i] = r[i - 2] + a[i];
	}
	ma = 0;
	for(int i = 2; i <= n; i += 2) {
		ma = max(ma, d[i] - r[i]);
		e[i] = ma + r[i];
	}
	cout << D(n) << endl;
	return 0;
}

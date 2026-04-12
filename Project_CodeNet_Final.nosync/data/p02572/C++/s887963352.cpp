#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll a[N], b[N];
const int M = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	ll res = 0;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}
	for(int i = n; i >= 1; i--) {
		res = (res + (a[i] * (b[i - 1] % M)) % M) % M;
	}
	cout << res << endl;
	return 0;
}
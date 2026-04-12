#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 2e5 + 100;

int n; ll a[N], L[N], R[N], ans = 0;


int main() {
	cin >> n;
	for(int i = 1;i <= n; ++i)
		cin >> a[i];
	L[1] = a[1] % mod;
	for(int i = 2;i <= n; ++i)
		L[i] = (L[i - 1] + a[i]) % mod;
	R[n] = a[n] % mod;
	for(int i = n - 1;i >= 1; --i)
		R[i] = (R[i + 1] + a[i]) % mod;
	for(int i = 1;i <= n; ++i)
		ans = (ans + (a[i] * (R[i + 1])) % mod) % mod;
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, m, k, a=1, b=1, ans, M=1e9+7;
int main() {
	ll i;
	cin >> n >> m >> k;
	for(i=1; i<=k-2; i++) {
		a = a * (n * m - i - 1) % M;
		b = b * i % M;
	}
	for(i=M-2; i; i/=2) {
		if(i&1) a = a * b % M;
		b = b * b % M;
	}
	b = a * n % M * n % M;
	for(i=1; i<m; i++) ans += b * i % M * (m-i) % M;
	b = a * m % M * m % M;
	for(i=1; i<n; i++) ans += b * i % M * (n-i) % M;
	cout << ans % M;
	return 0;
}

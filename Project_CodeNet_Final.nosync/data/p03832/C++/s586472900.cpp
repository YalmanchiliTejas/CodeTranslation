#include <iostream>
#include <cstdio>
#define N 1005
using namespace std;
typedef long long ll;

ll n, a, b, c, d, M=1e9+7, dp[N]={1}, fac[N]={1}, fiv[N]={1};

ll pow(ll p, ll q) {
	return q ? pow(p*p%M, q/2) * (q&1 ? p : 1) % M : 1;
}

int main() {
	ll i, j, k;
	cin >> n >> a >> b >> c >> d;
	for(i=1; i<=n; i++) {
		fac[i] = fac[i-1] * i % M;
		fiv[i] = pow(fac[i], M-2);
	}
	for(i=a; i<=b; i++) for(j=n; j>=0; j--) for(k=c; k<=d && j-k*i>=0; k++) {
		dp[j] = (dp[j] + dp[j-k*i] * pow(fiv[i], k) % M * fiv[k] % M) % M;
	}
	cout << dp[n] * fac[n] % M;
	return 0;
}
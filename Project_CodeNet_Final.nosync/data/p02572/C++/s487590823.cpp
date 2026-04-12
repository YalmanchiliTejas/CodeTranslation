#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 200010
using namespace std;

ll n, a, ans, sum;

inline ll read(){
	ll s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) w *= ch == '-' ? -1 : 1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}

int main(){
	n = read();
	for (ll i = 1; i <= n; ++i){
		a = read();
		ans = (ans + (sum * a) % mod) % mod;
		sum = (sum + a) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
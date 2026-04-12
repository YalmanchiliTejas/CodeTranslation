#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 1e9+7, N = 2e5+10;
ll q[N], pre[N];
int main() {
	int n;
	scanf("%d", &n);
	ll res = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld",&q[i]);
		pre[i] = q[i];
	}
	for(int i = 1; i <= n; i++){
		pre[i] = (pre[i] + pre[i-1]) % mod;
		res = (res + q[i] * pre[i-1] % mod) % mod;
	}
	
	printf("%lld", res);
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
constexpr int MOD = 1e9+7;
int n;
ll ac, a, ans;
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%lld", &a);
		(ac += a) %= MOD;
		(ans -= a * a) %= MOD;
	}
	(ans += ac * ac) %= MOD;
	if(ans < 0) ans += MOD;
	if(ans % 2) ans += MOD;
	printf("%lld\n", ans / 2);
}
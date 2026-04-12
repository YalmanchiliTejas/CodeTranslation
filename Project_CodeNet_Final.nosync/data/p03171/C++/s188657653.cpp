#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 3005
using namespace std;
typedef long long ll;
ll n, top, a[N], dp[2][N][N];

ll f(ll bas, ll son, ll d){
	ll &r = dp[d][bas][son];
	if(son < bas)
		return 0;
	if(r != -1)
		return r;
	if(d){
		r = max(a[bas] + f(bas + 1, son, 0), a[son] + f(bas, son - 1, 0));
	}else{
		r = min(-a[bas] + f(bas + 1, son, 1), -a[son] + f(bas, son - 1, 1));
	}
	return r;

}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	memset(dp, -1, sizeof dp);
	scanf("%lld",&n);
	for(ll i = 1; i <= n; i++){
		scanf("%lld", a + i);
		top += a[i];
	}
	printf("%lld\n", f(1, n, 1));
	return 0;
}
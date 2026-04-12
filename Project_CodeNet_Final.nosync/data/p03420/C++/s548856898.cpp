#include <bits/stdc++.h>

using namespace std;

#define ll 			long long
#define db			double
#define up(i,j,n)		for (ll i = j; i <= n; i++)
#define down(i,j,n)	for (ll i = j; i >= n; i--)
#define cadd(a,b)		a = add (a, b)
#define cpop(a,b)		a = pop (a, b)
#define cmul(a,b)		a = mul (a, b)
#define pr			pair<int, int>
#define fi			first
#define se			second
#define SZ(x)		(int)x.size()
#define bin(i)		(1 << (i))
#define Auto(i,node)	for (int i = LINK[node]; i; i = e[i].next)

template<typename T> inline bool cmax(T & x, T y){return y > x ? x = y, true : false;}
template<typename T> inline bool cmin(T & x, T y){return y < x ? x = y, true : false;}

int main(){
	ll n, k, ans = 0; scanf("%lld%lld", &n, &k);
	up (b, k + 1, n) {
		ll cl = k, cr = b - 1;
		ans += (cr - cl + 1) * ((n + 1) / b);
		if (cl == 0) ans--;
		if ((n + 1) % b == 0) continue;
		cmin(cr, n % b);
		if (cl <= cr) ans += cr - cl + 1;
	}
	printf("%lld\n", ans);
	return 0;
}

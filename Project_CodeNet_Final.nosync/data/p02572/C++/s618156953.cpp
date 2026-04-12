#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <queue>
#define N 100010
#define Pa pair<ll,int>
#define ll long long
#define mo ((ll)1e9+7)
//10000000000037ll
//21993833369ll
#define db double
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define drep(i,a,b) for(int i=a;i>=b;--i)
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
bool cmp(int a, int b) {return a > b;}
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
ll a[200010]; ll s[200010];
int main() {
	ll n = read();
	rep(i, 1, n)a[i] = read(), s[i] = (s[i - 1] + a[i]) % mo;
	ll ans = 0;
	rep(i, 2, n) {
		//printf("%lld\n", s[i - 1] * 1ll * a[i]);
		ans = (ans + s[i - 1] * 1ll * a[i]) % mo;
	}
	printf("%lld\n", ans);
	return 0;
}

#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
const ll inf = 1e18;

ll n;
pair<ll,ll> a[200005];

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i].X,&a[i].Y);
		if(a[i].X > a[i].Y) swap(a[i].X, a[i].Y);
	}
	sort(a+1, a+1+n);
	ll N1 =	inf, X1 = -inf, N2 = inf, X2 = -inf;
	for(ll i=1;i<=n;i++) {
		N1 = min(a[i].X, N1); X1 = max(a[i].X, X1);
		N2 = min(a[i].Y, N2); X2 = max(a[i].Y, X2);
	}
	ll ans = (X2 - N2) * (X1 - N1), C = inf;
	for(ll i=1;i<=n;i++) {
		ans = min(ans, (X2 - N1)*(X1 - min(C, a[i].X)));
		C = min(C, a[i].Y);
		X1 = max(X1, a[i].Y);
	}
	printf("%lld\n",ans);
}

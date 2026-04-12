#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (1LL << 55)
#define MOD (1000 * 1000 * 1000 + 7)
#define maxn 200111

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main(){
	ll n, k;
	scanf("%lld%lld", &n, &k);

	ll ans = 0;
	for(ll b = k + 1; b <= n; b++){
		ll cur = n / b;
		ll x = cur * (b - k);
		x += max((n % b) - k + (k > 0 ? 1 : 0), 0LL);

		//cout << b << "  " << x << endl;
		ans += x;
	}
	printf("%lld\n", ans);
	return 0;
}
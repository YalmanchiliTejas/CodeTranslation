#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;

	ll ans = 0;
	for(ll b = k+1; b <= n; b++){
		ll q = n / b;
		ll r = n % b;

		ans += q * (b - k) + max(r - k + 1, 0LL);
	}

	if(k == 0) ans -= n;

	cout << ans << endl;
}
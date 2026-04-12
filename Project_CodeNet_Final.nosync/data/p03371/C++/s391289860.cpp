#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 3e6 + 5;
const long long MOD = 1e9 + 9;
const long double eps = 1e-6;

#define mp make_pair
#define pb push_back
#define all(temp) temp.begin(), temp.end()
#define REP(i,n) for(int i = 0; i < n; ++i)

int main()
{
	//freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	ll a,b,c; cin >> a >> b >> c;
	ll x,y; cin >> x >> y;

	ll ans = x * a + y * b;

	for(ll i = 0; i <= 2 * max(x,y); i += 2){
        ll needA = max(0ll, x - i / 2);
		ll needB = max(0ll, y - i / 2);
		ll cur = i * c + needA * a + needB * b;
		ans = min(ans, cur);
	}
	cout << ans;

    return 0;
}

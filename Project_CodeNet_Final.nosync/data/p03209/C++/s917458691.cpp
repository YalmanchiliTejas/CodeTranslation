#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define repe_r(i,s,n)for(int i = n;i>=0;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e20;// 000000007;// 1e9 + 7
ll Pow(ll n, ll p) {
	if (p == 0)return 1;
	if (p == 1)return n;
	ll t = Pow(n, p / 2);
	if (p & 1) return (t * t % MOD) * n % MOD;
	else return t * t % MOD;
}
int main() {
	ll n, x; cin >> n >> x;
	ll a = Pow(2, n + 2) - 3;

	ll ans = 0;
	repe_r(i, 0, n) {
		if (x > a / 2 + 1) {
			ans += Pow(2, i);
			x -= Pow(2, i + 1) - 1;
		}
		else if (x < a / 2 + 1) {
			x--;
		}
		else {
			ans += Pow(2, i);
			break;
		}
		a = Pow(2, i + 1) - 3;
	}

	cout << ans << endl;

	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
int main() {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t;
    t = 1;
	while (t--) {
		ll n, x, m;
		cin >> n >> x >> m;
		ll ans = x;
		ll pos[m + 5];
		memset(pos, -1, sizeof pos);
		pos[x] = 1;
		ll a = x;
		ll f = -1, s = -1, rest = 0;
		ll sum[m + 5];
		sum[0] = 0;
		sum[1] = x;
		for (ll i = 2; i <= n; ++i) {
			a = (a * a) % m;
			sum[i] = a;
			sum[i] += sum[i - 1];
			if (a == 0)
				break;
			else if (a == 1) {
				ans += n - i + 1;
				break;
			}
			if (pos[a] == -1) {
				pos[a] = i;
				ans += a;
			}
			else {
				f = pos[a];
				s = i - 1;
				rest = n - i + 1;
				break;
			}
		}
		//cout << ans << endl;
		if (rest != 0) {
			ans += (rest / (s - f + 1)) * (sum[s] - sum[f - 1]);
			ll temp = rest % (s - f + 1);
			ans += sum[f + temp - 1] - sum[f - 1];
		}
		cout << ans << endl;
	}
}
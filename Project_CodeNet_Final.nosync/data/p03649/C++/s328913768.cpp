#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x, n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;   
typedef pair<P,P> PP;

//-----------------------------------------------------------------------------

int n;
ll a[50];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

	cin >> n;
	REP(i, n) cin >> a[i];

	ll ans = 0;
	while (true) {
		ll sum = 0;
		ll cnt[n] = {};
		REP(i, n) {
			if (a[i] > n - 1) {
				cnt[i] = (a[i] - (n - 1)) / n + !!((a[i] - (n - 1)) % n);
				sum += cnt[i];
			}
		}
		if (sum == 0) break;
		ans += sum;
		REP(i, n) {
			a[i] = a[i] - cnt[i] * n + (sum - cnt[i]);
		}
	}
	cout << ans << endl;

    return 0;
}

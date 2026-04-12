#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
//-------
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	ll ans = (m != 0) * (n - m);
	for(int base = m + 1; base <= n; base++) {
		for(int l = base; l <= n; l += base) {
			int r = min(n + 1, l + base);
			ans += max(0, r - (l + m));
		}
		ans += n - base;
	}
	printf("%lld\n", ans);
	return 0;
}


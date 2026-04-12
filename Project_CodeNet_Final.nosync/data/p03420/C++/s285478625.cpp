#include <bits/stdc++.h>
using namespace std;
#define MAXN 200009
#define MAXM 320
#define MOD 1000000007
#define INF 1000000009
#define FOR(x,n) for(int x=0; x<n; x++)
#define FOR1e(x,n) for(int x=1; x<=n; x++)
#define pb push_back
typedef pair<int, int> ii;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	if (k == 0) ans = 1;

	for (ll b = 2; b <= n; b++) {
		if (k >= b) continue;
		ll bound = (n)/b;
		ans += bound*(b-k);
		ll tmp = n - bound*b;

		ans += max(0LL, tmp-k+1);

	//	printf("%lld %lld\n", b, ans);
	}
	cout << ans << endl;
	
}
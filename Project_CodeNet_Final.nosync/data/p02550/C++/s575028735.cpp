#include <bits/stdc++.h>
 
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 100005;

ll n, x, m;
int dist[N], nxt[N];

ll getDist(int start, int cur) {
	if (nxt[cur] == start) return cur;
	return cur + getDist(start, nxt[cur]);
}

ll getDistWithSomeDistance(int cur, int d, int t) {
	if (t == 0) return 0;
	if (d == t) return cur;
	return cur + getDistWithSomeDistance(nxt[cur], d+1, t);
}

int getLength(int start, int cur) {
	if (nxt[cur] == start) return 1;
	return 1 + getLength(start, nxt[cur]);
}

int main() {
	scanf("%lld %lld %lld", &n, &x, &m);
	reset(nxt, -1);
	dist[x] = 1;
	ll ans = x;
	int cnt = 1;
	while (cnt < n) {
		ll tmp = (x*x) % m;
		if (tmp == 0) {
			break;
		}
		nxt[x] = tmp;
		if (dist[tmp] > 0) {
			n -= dist[x];
			ll dist = getDist(tmp, tmp);
			int len = getLength(tmp, tmp);
			ans += (n/len) * dist;
			ans += getDistWithSomeDistance(tmp, 1, n % len);
			break;
		}
		dist[tmp] = dist[x] + 1;
		ans += tmp;
		x = tmp;
		cnt++;
	}

	printf("%lld\n", ans);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;

ll n;
int m, x;

int vis[N];

int main() {
	scanf("%lld %d %d", &n, &x, &m);

	ll ans = 0;
	ll ptr = x;
	for(int it = 1; n > 0 and !vis[ptr]; it++) {
		n--;
		vis[ptr] = it;
		ans += ptr;
		ptr = ptr * ptr % m;
	}

	if(!n) return printf("%lld\n", ans), 0;

	ll tot = 0;
	int size = 0;
	for(ll u = ptr; ; ) {
		tot += u;
		size++;
		u = u * u % m;
		if(u == ptr) break; 
	}

	ans += n / size * tot;
	n %= size;
	while(n--) {
		ans += ptr;
		ptr = ptr * ptr % m;
	}

	printf("%lld\n", ans);
}

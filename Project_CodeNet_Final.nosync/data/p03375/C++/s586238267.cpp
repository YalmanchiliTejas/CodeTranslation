#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define MP std::make_pair
#define PII std::pair<int, int>
#define all(x) (x).begin(), (x).end()
#define CL(a, b) memset(a, b, sizeof a)
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, r, l) for (int i = (r); i >= (l); -- i)
#define PE(x, a) for (int x = head[a]; x;x = edge[x].next)

typedef long long ll;

const int MAXN = 3e3 + 7;

int n;
ll C[MAXN][MAXN], S[MAXN][MAXN], HA, _2[MAXN];

ll fp(ll a, ll b, ll p) {
	ll r = 1;
	while (b) {
		if (b & 1) r = r * a % p;
		b >>= 1, a = a * a % p;
	}
	return r;
}

int main() {
	scanf("%d %lld", &n, &HA);
	S[0][0] = C[0][0] = 1;
	rep(i, 1, n + 2) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % HA, S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j] % HA) % HA;
	}

	ll ans = 0;
	rep(i, 0, n) {
		ll gx = 0, f22 = fp(2, fp(2, n - i, HA - 1), HA), fn = 1, base = fp(2, n - i, HA);
		rep(j, 0, i) gx = (gx + S[i + 1][j + 1] * f22 % HA * fn % HA) % HA, fn = fn * base % HA;
		gx = gx * C[n][i] % HA;
		if (i & 1) ans = (ans + HA - gx) % HA;
		else ans = (ans + gx) % HA;
	}
	printf("%lld\n", ans);
	return 0;
}
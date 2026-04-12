#include <bits/stdc++.h>

using namespace std;

#define m2(x) ((x) * (x))
#define mp(a, b) make_pair(a, b)
#define ms(a, w) memset(a, w, sizeof(a))
#define fi first
#define se second

typedef long long LL;
typedef pair <int, int> ii;

const int MAXN = 200000 + 10;
const int INF = 1000000001;
const int MOD = 1000000000 + 7;
const int MAX = 200000;

int a[MAXN], b[MAXN];

int main () {
//	ios::sync_with_stdio(false);
//	freopen("1.in", "r", stdin);
//	freopen("CirclesGame.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int p = 1, q = n;
	for (int i = n; i >= 1; i--)
		if (n - i & 1)
			b[q--] = a[i];
		else
			b[p++] = a[i];
	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);

	return 0;
}

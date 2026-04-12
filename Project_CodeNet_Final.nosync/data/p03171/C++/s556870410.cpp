#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

ll vec[3000];
ll dp[3000][3000][2];

ll go(int l, int r, int tu) {
	if (l > r) return 0;
	if (dp[l][r][tu] > -1e17) return dp[l][r][tu];

	ll ret;
	if (tu == 0) ret = max(go(l, r - 1, tu ^ 1) + vec[r], go(l + 1, r, tu ^ 1) + vec[l]);
	else ret = min(go(l, r - 1, tu ^ 1) - vec[r], go(l + 1, r, tu ^ 1) - vec[l]);

	return dp[l][r][tu] = ret;
}

int main() {
	memset(dp, -0x3f, sizeof(dp));


	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &vec[i]);

	printf("%lld", go(0, n - 1, 0));
}
#include <cstdio>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
//#include <memory.h>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <cassert>
#include <unordered_map>
#define P pair<int, int>
#define LL long long
#define LD long double
#define PLL pair<LL, LL>
#define mset(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for (int i = a; i < b; i++)
#define PI acos(-1.0)
#define random(x) rand() % x
#define debug(x) cout << #x << " " << x << "\n"
using namespace std;
const int inf = 0x3f3f3f3f;
const LL __64inf = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
const int MAX = 2e3 + 50;
#else
const int MAX = 1e6 + 50;
#endif
const int mod = 1e9 + 7;
void file_read() {
#ifdef DEBUG
	freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
#endif
}

LL a[MAX];
LL s[MAX];
int main() {
	file_read();
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = (s[i-1] + a[i]) % mod;
	}
	LL ans = 0;
	for(int i = 2; i <= n; i++) {
		ans += a[i] * (s[i-1]) % mod;
		ans %= mod;
	}
	printf("%lld\n", ans);
}
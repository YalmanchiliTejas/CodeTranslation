#include <bits/stdc++.h>
#define X first
#define Y second
 
using namespace std;
typedef long long llint;
 
const int maxn = 2e5+10;
const int base = 31337;
const llint mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 20;
const int off = 1 << logo;
const int treesiz = off << 1;

int n;
llint niz[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", niz+i);

	llint sum = 0;
	llint sol = 0;
	for (int i = 0; i < n; i++) {
		sol += (niz[i] * sum) % mod;
		sol %= mod;
		sum += niz[i], sum %= mod;
	}
	printf("%lld\n", sol);
	return 0;
}
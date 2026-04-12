#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int main()
{
	// freopen("ARC091-D.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	ll ans = 0; 
	for (int b = k + 1; b <= n; b++)
		ans += (ll)(n / b) * (b - k) + std::max(n % b - k + 1, 0) - !k; 
	printf("%lld\n", ans);
	return 0; 
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n)	 for(int i = 0; i < (n); i++)
#define all(a)		 begin(a), end(a)

typedef long long int		   ll;
typedef long long unsigned int llu;

void solve(ll r, ll g, ll b) {
	if((r * 100 + g * 10 + b) % 4 == 0) printf("YES");
	else printf("NO");
}

int main() {
	ll r;
	ll g;
	ll b;
	scanf("%lld", &r);
	scanf("%lld", &g);
	scanf("%lld", &b);
	solve(r, g, b);
	return 0;
}

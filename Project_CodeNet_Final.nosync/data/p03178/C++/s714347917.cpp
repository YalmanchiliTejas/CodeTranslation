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
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

char s[10001];
int dp[10000][100][2][2]; // 타이트하다. 크다.
int n, d;

int go(int o, int sum, int st, int bb) {
	if (o == n) return sum == 0 && bb == 0;
	if (dp[o][sum][st][bb] != -1) return dp[o][sum][st][bb];

	ll ret = sum == 0;
	for (int i = 0; i < 10; i++) 
		ret += go(o + 1, (sum + i) % d, (st && i == s[o]) ? 1 : 0, (bb || st && i > s[o] ? 1 : 0));

	ret %= MOD;
	return dp[o][sum][st][bb] = ret;
}


int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s", s);
	n = strlen(s);

	for (int i = 0; i < n; i++)
		s[i] -= '0';

	scanf("%d", &d);
	
	ll ret = 0;
	for (int i = 1; i < 10; i++) 
		ret += go(1, i % d, i == s[0], i > s[0]);

	printf("%lld", ret % MOD);
}
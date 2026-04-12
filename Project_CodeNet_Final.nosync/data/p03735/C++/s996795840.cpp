#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll in[400050][2];
pii u[400050];
int rch[400050][2];
int getpos(int x) {
	return in[u[x].first][u[x].second];
}

bool chk[400050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &in[i][0], &in[i][1]);
	for (i = 1; i <= N; i++) {
		u[i] = pii(i, 0);
		u[i + N] = pii(i, 1);
	}
	sort(u + 1, u + 2 * N + 1, [](pii a, pii b) {
		return in[a.first][a.second] < in[b.first][b.second];
	});
	for (i = 1; i <= 2 * N; i++) rch[u[i].first][u[i].second] = i;

	int mx2 = 1, tp;
	for (i = 2 * N; i >= 1; i--) {
		if (chk[u[i].first]) break;
		chk[u[i].first] = true;
	}
	tp = i;
	memset(chk, 0, sizeof(chk));

	chk[u[1].first] = true;
	mx2 = rch[u[1].first][1 ^ u[1].second];
	ll ans = LL_INF;
	for (i = 2; i <= 2*N; i++) {
		int mx1 = rch[u[i].first][1 ^ u[i].second];
		ans = min(ans, (ll)(getpos(max(mx1, tp)) - getpos(1)) * (getpos(2 * N) - getpos(i)));
		ans = min(ans, (ll)(getpos(2 * N) - getpos(1)) * (getpos(max(mx2, tp)) - getpos(i)));

		if (chk[u[i].first]) break;
		chk[u[i].first] = true;
		mx2 = max(mx2, rch[u[i].first][1 ^ u[i].second]);
	}
	return !printf("%lld\n", ans);
}
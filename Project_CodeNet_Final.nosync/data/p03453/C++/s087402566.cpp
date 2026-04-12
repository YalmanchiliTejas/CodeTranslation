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

int IT_MAX = 1 << 19;
int MOD = 10000000;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 100005;
const int MM = 1000000007;

vector<pii> G[MX];
int N, M, S, T;

void dijkstra(int st, ll dist[MX], ll cnt[MX])
{
	for(int i = 1; i <= N; i++) dist[i] = 1e18, cnt[i] = 0;
	priority_queue<pli, vector<pli>, greater<pli>> Q;
	Q.emplace(0ll, st);
	cnt[st] = 1; dist[st] = 0;
	while(Q.size()){
		pli p = Q.top(); Q.pop();
		int u = p.second;
		if( dist[u] != p.first ) continue;
		for(pii e : G[u]){
			ll d = p.first + e.first;
			int c = e.second;
			if( dist[c] == d ) cnt[c] = (cnt[c] + cnt[u]) % MM;
			else if( dist[c] > d ){
				cnt[c] = cnt[u], dist[c] = d;
				Q.emplace(d, c);
			}
		}
	}
}

ll sq(ll x){ return x*x%MM; }

ll dS[MX], dT[MX], cS[MX], cT[MX];
int main()
{
	scanf("%d%d%d%d", &N, &M, &S, &T);
	for(int i = 1; i <= M; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c); c *= 2;
		G[a].emplace_back(c, b);
		G[b].emplace_back(c, a);
	}
	dijkstra(S, dS, cS);
	dijkstra(T, dT, cT);
	ll d = dS[T] / 2;
	ll ans = cS[T] * cT[S] % MM;
	for(int i = 1; i <= N; i++){
		if( dS[i] == d && dT[i] == d ) ans = (ans + MM - sq(cS[i] * cT[i]%MM)) % MM;
		for(pii e : G[i]){
			int a = i, b = e.second;
			if( dS[a] + e.first == dS[b] && dS[b] + dT[b] == 2*d && dS[a] + dT[a] == 2*d && dS[a] < d && dS[b] > d ){
				ans = (ans + MM - sq(cS[a]*cT[b]%MM)) % MM;
			}
		}
	}
	printf("%lld\n", ans);
}

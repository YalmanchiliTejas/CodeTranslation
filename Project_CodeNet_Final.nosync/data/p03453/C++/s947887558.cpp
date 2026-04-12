#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100000;
const int MAXM = 200000;
const int MOD = 1000000007;

int n, m, s, t;
int ghead[MAXN], gnxt[2 * MAXM], gto[2 * MAXM], glen[MAXM];

ll ds[MAXN], dt[MAXN]; int wayss[MAXN], wayst[MAXN];
priority_queue<pair<ll, int> > pq;

void dcalc(ll *d,int *ways, int s) {
	REP(i, n) d[i] = LLONG_MAX, ways[i] = 0; pq = priority_queue<pair<ll, int> >();
	d[s] = 0, ways[s] = 1, pq.push(MP(-d[s], s));
	while (!pq.empty()) {
		ll cd = -pq.top().first; int at = pq.top().second; pq.pop();
		if (cd > d[at]) continue;
		for (int x = ghead[at]; x != -1; x = gnxt[x]) {
			int to = gto[x]; ll nd = cd + glen[x >> 1];
			if (nd < d[to]) d[to] = nd, ways[to] = ways[at], pq.push(MP(-d[to], to));
			else if (nd == d[to]) ways[to] = (ways[to] + ways[at]) % MOD;
		}
	}
	REP(i, n) assert(d[i] != LLONG_MAX);
}

void run() {
	scanf("%d%d%d%d", &n, &m, &s, &t); --s, --t;
	REP(i, n) ghead[i] = -1;
	REP(i, m) {
		int a, b; scanf("%d%d%d", &a, &b, &glen[i]); --a, --b;
		gnxt[2 * i + 0] = ghead[a], ghead[a] = 2 * i + 0, gto[2 * i + 0] = b;
		gnxt[2 * i + 1] = ghead[b], ghead[b] = 2 * i + 1, gto[2 * i + 1] = a;
	}

	dcalc(ds, wayss, s), dcalc(dt, wayst, t);
	//REP(i, n) printf("%d: ds=%lld wayss=%d dt=%lld wayst=%d\n", i + 1, ds[i], wayss[i], dt[i], wayst[i]);
	ll dtot = ds[t]; int waystot = wayss[t];
	int ret = 0;
	REP(i, n) {
		if (ds[i] + dt[i] != dtot || ds[i] != dt[i]) continue;
		//printf("at node %d: %lld\n", i + 1, (dtot + MOD - (ll)wayss[i] * wayst[i] % MOD) % MOD);
		int cnt1 = (ll)wayss[i] * wayst[i] % MOD;
		int cnt2 = (waystot + MOD - cnt1) % MOD;
		ret = (ret + (ll)cnt1*cnt2) % MOD;
	}
	REP(x, 2*m) {
		int a = gto[x ^ 1], b = gto[x];
		if (ds[a] + glen[x >> 1] + dt[b] != dtot || 2 * ds[a] >= dtot || 2 * dt[b] >= dtot) continue;
		//printf("at edge %d->%d: %lld\n", a + 1, b + 1, (dtot + MOD - (ll)wayss[a] * wayst[b] % MOD) % MOD);
		int cnt1 = (ll)wayss[a] * wayst[b] % MOD;
		int cnt2 = (waystot + MOD - cnt1) % MOD;
		ret = (ret + (ll)cnt1*cnt2) % MOD;
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}

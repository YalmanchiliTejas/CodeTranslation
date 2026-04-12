#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <random>
#include <regex>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define reach(i,a)	for(auto i:a)
#define rep(i,n)	for(int i=0;i<(int)n;i++)
#define REP(i,n)	for(int i=0;i<=(int)n;i++)
#define srep(i,a,n)	for(int i=a;i<(int)n;i++)
#define SREP(i,a,n)	for(int i=a;i<=(int)n;i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define RREP(i,n)	for(int i=n;i>=0;i--)
#define all(a)	(a).begin(),(a).end()
#define mp(a,b)	make_pair(a,b)
#define mt	make_tuple
#define pb	push_back
#define fst	first
#define scn second
int bitcnt(ll x) {
	x = ((x & 0xAAAAAAAAAAAAAAAA) >> 1) + (x & 0x5555555555555555);
	x = ((x & 0xCCCCCCCCCCCCCCCC) >> 2) + (x & 0x3333333333333333);
	x = ((x & 0xF0F0F0F0F0F0F0F0) >> 4) + (x & 0x0F0F0F0F0F0F0F0F);
	x = ((x & 0xFF00FF00FF00FF00) >> 8) + (x & 0x00FF00FF00FF00FF);
	x = ((x & 0xFFFF0000FFFF0000) >> 16) + (x & 0x0000FFFF0000FFFF);
	x = ((x & 0xFFFFFFFF00000000) >> 32) + (x & 0x00000000FFFFFFFF);
	return x;
}
int bitcnt(int x) {
	x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
	x = ((x & 0xCCCCCCCC) >> 2) + (x & 0x33333333);
	x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
	x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
	x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
	return x;
}
ll gcd(ll a, ll b) {
	return a%b == 0 ? b : gcd(b, a%b);
}
#define debug(x)	cout<<"case #" << x << ": " << endl
#define DEBUG 0
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ld eps = 1e-9;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

ll dists[100000], cnts[100000];
ll distt[100000], cntt[100000];
vector<pii> edge[100000];
bool visited[100000];

int main() {
	int n, m;	cin >> n >> m;
	int s, t;	cin >> s >> t;	s--;	t--;
	rep(i, m) {
		int u, v, d;	cin >> u >> v >> d;	u--;	v--;
		edge[u].push_back(mp(v, d));
		edge[v].push_back(mp(u, d));
	}
	rep(i, n)	dists[i] = distt[i] = inf;
	dists[s] = distt[t] = 0;
	cnts[s] = cntt[t] = 1;
	priority_queue<pair<ll, int>> pq;
	pq.push(mp(-0, s));
	while (!pq.empty()) {
		auto it = pq.top();	pq.pop();
		ll d = -it.first;
		int pos = it.second;
		if (d > dists[pos])	continue;
		rep(i, edge[pos].size()) {
			ll tod = d + edge[pos][i].second;
			int to = edge[pos][i].first;
			if (tod < dists[to]) {
				dists[to] = tod;
				pq.push(mp(-tod, to));
			}
		}
	}
	rep(i, n)	pq.push(mp(-dists[i], i));
	while (!pq.empty()) {
		auto it = pq.top();	pq.pop();
		rep(i, edge[it.second].size()) {
			ll d = -it.first + edge[it.second][i].second;
			int to = edge[it.second][i].first;
			if (dists[to] == d)	cnts[to] = (cnts[to] + cnts[it.second]) % mod;
		}
	}
	rep(i, n)	pq.push(mp(dists[i], i));
	while (!pq.empty()) {
		auto it = pq.top();	pq.pop();
		rep(i, edge[it.second].size()) {
			ll d = it.first - edge[it.second][i].second;
			int to = edge[it.second][i].first;
			if (dists[to] == d)	cntt[to] = (cntt[to] + cntt[it.second]) % mod;
		}
	}
	ll ret = (cnts[t] * cnts[t]) % mod;
	pq.push(mp(dists[t], t));
	while (!pq.empty()) {
		auto it = pq.top();	pq.pop();
		ll tod = it.first;
		int to = it.second;
		if (visited[to])	continue;
		visited[to] = true;
		if (tod * 2 == dists[t]) {
			ll st = (cnts[to] * cntt[to]) % mod;
			ll sub = (st*st) % mod;
			ret = (ret + mod - sub) % mod;
		}
		rep(i, edge[to].size()) {
			ll fromd = tod - edge[to][i].second;
			int from = edge[to][i].first;
			if (fromd != dists[from])	continue;
			if (tod * 2 > dists[t] && dists[t] > fromd * 2) {
				ll st = (cnts[from] * cntt[to]) % mod;
				ll sub = (st*st) % mod;
				ret = (ret + mod - sub) % mod;
			}
			pq.push(mp(fromd, from));
		}
	}
	cout << ret << endl;
	return 0;
}
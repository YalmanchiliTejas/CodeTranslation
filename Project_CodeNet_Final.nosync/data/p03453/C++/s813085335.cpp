#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
#include <functional>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(u) (u).begin(),(u).end()

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

typedef pair<int, int> PII;
typedef pair<LL, int> PLI;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const int MR = 1e5 + 10;
const int MOD = 1e9 + 7;
const LL inf = 1e18;

vector<PII> g[MR];

PLI cost[MR][2];
bool done[MR][2];

vector<int> pr[MR][2];

int go(int S, int T, int N)
{
	priority_queue<PLI, vector<PLI>, greater<PLI> > Q[2];
	REP(i, N)
		cost[i][0] = cost[i][1] = MP(inf, 0);

	cost[S][0] = MP(0, 1);
	Q[0].push(MP(0, S));

	cost[T][1] = MP(0, 1);
	Q[1].push(MP(0, T));

	while (!(Q[0].empty() && Q[1].empty()))
	{
		bool sel = 0;
		if (Q[0].empty() ||
			(!Q[1].empty() && Q[1].top().first < Q[0].top().first))
			sel = 1;

		auto akt = Q[sel].top(); Q[sel].pop();
		if (done[akt.second][sel])
			continue;

		// przetwarzamy wlasciwy koszt
		done[akt.second][sel] = 1;

		for (const auto &p : g[akt.second])
		{
			if (cost[p.first][sel].first > cost[akt.second][sel].first + p.second)
			{
				cost[p.first][sel].first = cost[akt.second][sel].first + p.second;
				cost[p.first][sel].second = cost[akt.second][sel].second;
				Q[sel].push(MP(cost[p.first][sel].first, p.first));
				pr[p.first][sel].clear();
				pr[p.first][sel].push_back(akt.second);
			}
			else if (cost[p.first][sel].first == cost[akt.second][sel].first + p.second)
			{
				cost[p.first][sel].second = (cost[p.first][sel].second + cost[akt.second][sel].second) % MOD;
				pr[p.first][sel].push_back(akt.second);
			}
		}
	}

	// zwroc wszystkie sposoby, nawet kolizyjne, potem bedziemy od tego odejmowac
	return cost[T][0].second*(LL)cost[T][0].second % MOD;
}

// ======== BICONNECTED-COMPONENTS by Piotr Bejda ========
vector<PII> E;

bool inQ[MR];
void reconstruct(int T)
{
	queue<int> Q;
	Q.push(T);
	inQ[T] = 1;

	while (!Q.empty())
	{
		int akt = Q.front(); Q.pop();
		for (int i : pr[akt][0])
		{
			E.push_back(MP(i, akt));
			if (!inQ[i])
			{
				Q.push(i);
				inQ[i] = 1;
			}
		}
	}
}

int sqr(int x)
{
	return x*(LL)x % MOD;
}

int main()
{
	int N, M, S, T;
	scanf("%d%d%d%d", &N, &M, &S, &T); S--; T--;
	REP(i, M)
	{
		int U, V, D;
		scanf("%d%d%d", &U, &V, &D); U--; V--;
		g[U].push_back(MP(V, D));
		g[V].push_back(MP(U, D));
	}

	int res = go(S, T, N);

	// spr czy przypadkiem nie bedzie to 0
	// wez tylko graf min sciezek
	reconstruct(T);


	//wierzcholki
	REP(i, N)
		if (inQ[i] && cost[i][0].first == cost[i][1].first)
			res = (res + MOD - sqr(cost[i][0].second*(LL)cost[i][1].second % MOD)) % MOD;

	// krawedzie
	for (const auto & p : E)
	{
		// pierwszy wierzcholek powinien byc zawsze blizej zrodla
		assert(cost[p.first][0].first < cost[p.second][0].first);

		if (cost[p.second][0].first >= cost[p.second][1].first && cost[p.first][1].first >= cost[p.first][0].first
			&& cost[p.first][0].first != cost[p.first][1].first
			&& cost[p.second][0].first != cost[p.second][1].first)
			res = (res + MOD - sqr(cost[p.first][0].second*(LL)cost[p.second][1].second%MOD)) % MOD;
	}

	printf("%d\n", res);

	return 0;
}
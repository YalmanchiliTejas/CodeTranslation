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
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const int MR = 1e5 + 10;

vector < int > g[MR];

bool done[MR], match[MR];

bool dfs(int nr)
{
	done[nr] = 1;
	bool childToMatch = 0;
	for (auto v : g[nr])
		if (!done[v])
		{
			if (!dfs(v))
				return 0;
			if (!match[v])
			{
				// spr czy ma wiecej, niz 1 dziecko niezmatchowane
				if (childToMatch)
					return 0;
				childToMatch = 1;
			}
		}

	// odznacz czy matchujesz goscia z dzieckiem
	match[nr] = childToMatch;

	return 1;
}

int main()
{
	int N;
	scanf("%d", &N);

	if (N & 1)
	{
		printf("First\n");
		return 0;
	}

	REP(i, N - 1)
	{
		int a, b;
		scanf("%d%d", &a, &b); a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if (dfs(0))
		printf("Second\n");
	else
		printf("First\n");

	return 0;
}
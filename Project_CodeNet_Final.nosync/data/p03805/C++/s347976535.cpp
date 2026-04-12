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

const int MR = 10;

vector < int > g[MR];

bool done[MR];

int res;

vector < int > S;

int N, M;

void dfs(int nr)
{
	done[nr] = 1;
	S.push_back(nr);

	REP(i,g[nr].size())
		if(!done[g[nr][i]])
			dfs(g[nr][i]);

	if(S.size() == N)
		res++;

	S.pop_back();
	done[nr] = 0;
}

int main()
{
	scanf("%d%d", &N, &M);
	REP(i,M)
	{
		int a, b;
		scanf("%d%d", &a, &b);a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);

	printf("%d\n", res);
	return 0;
}
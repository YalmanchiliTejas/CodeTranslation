#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MAXN = 20;

int n, m, dp[MAXN][MAXN];

char p[MAXN][MAXN];

int main() {
	scanf("%d %d",&n,&m);
	FOR(i, 1, n + 1) scanf("%s",p[i] + 1);

	FOR(i, 1, n + 1) 
		FOR(j, 1, m + 1) 
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (p[i][j] == '#');

	int sve = 0;
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) sve += (p[i][j] == '#');
	if (dp[n][m] == sve) puts("Possible");
	else puts("Impossible");
	return 0;
}
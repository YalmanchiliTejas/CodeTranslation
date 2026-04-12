#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>
#include <complex>
#include <stdio.h>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LD PI = acos(-1.0);
const LL mod = 1000000007;
const LL INF = 1e9;
const LL MAXN = 10;

string A[MAXN];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int h, w, cnt = 0, r = 0, c = 0, res = 1;
	cin >> h >> w;
	REP(i, h) cin >> A[i];
	REP(i, h) REP(j, w)
		cnt += A[i][j] == '#';
	while (true)
	{
		if (r + 1 < h && A[r + 1][c] == '#')
		{
			++res;
			++r;
			continue;
		}
		if (c + 1 < w && A[r][c + 1] == '#')
		{
			++res;
			++c;
			continue;
		}
		break;
	}
	if (res == cnt) cout << "Possible";
	else cout << "Impossible";
	return 0;
}
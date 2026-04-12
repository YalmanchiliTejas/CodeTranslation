#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <complex>
#include <cassert>
#include <bitset>

#define enp     puts("**chkchkchkchkchk**")
#define A       first
#define B       second
#define MP      make_pair

using namespace std;

typedef long long ll;
typedef unsigned int uint;

const int INF = 0x60000000;
const int MINF = -1000000000;
const int mod = 1000000007;
const int cons = 100001;
const double pi = 3.141592653589793;
const int sqrtMax = 317;
const int blocks = cons / 3;

char M[15][15];
int h, w;
int maxcnt = 0;

void go(int y, int x, int cnt)
{
	int newcnt = cnt;
	if (M[y][x] == '#')newcnt++;

	if (y == h - 1 && x == w - 1)
	{
		maxcnt = max(maxcnt, newcnt);
		return;
	}


	if (y < h - 1)go(y + 1, x, newcnt);
	if (x < w - 1)go(y, x + 1, newcnt);
}

int main() 
{
	scanf("%d%d", &h, &w);

	int need = 0;
	for (int i = 0; i < h; i++)
	{
		scanf("%s", &M[i]);

		for (int j = 0; j < w; j++)
		{
			if (M[i][j] == '#')need++;
		}
	}

	go(0, 0, 0);

	if(maxcnt == need)puts("Possible");
	else puts("Impossible");

	return 0;
}
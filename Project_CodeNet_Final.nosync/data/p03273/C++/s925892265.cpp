#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
char str[N][N];
int row[N];
int col[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i] + 1;
		for (int j = 1; j <= m; j++)
		{
			row[i] |= str[i][j] == '#';
			col[j] |= str[i][j] == '#';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (row[i] == 0) continue;
		for (int j = 1; j <= m; j++)
		{
			if (col[j])
				putchar(str[i][j]);
		}
		puts("");
	}
	return 0;
}

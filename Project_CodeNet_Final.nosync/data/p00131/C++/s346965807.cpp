#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define PI 3.14159265359
#define INF 99999999
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
 
int n;
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};
int tile[10][10];
int flip[10][10];

int get(int x, int y)
{
	int c = tile[y][x];
	rep(d, 5)
	{
		int x2 = x + dx[d];
		int y2 = y + dy[d];
		if (0 <= x2 && x2 < 10 && 0 <= y2 && y2 < 10)
		{
			c += flip[y2][x2];
		}
	}
	return c % 2;
}

void print()
{
	rep(i, 10)
	{
		rep(j, 10)
		{
			if (j == 9)
			{
				printf("%d\n", flip[i][j]);
			} else {
				printf("%d ", flip[i][j]);
			}
		}
	}
}

bool calc()
{
	for (int i=1; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			if (get(j, i-1) != 0)
			{
				flip[i][j] = 1;
			}
		}
	}

	for (int j=0; j<10; j++)
	{
		if (get(j, 9) != 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	cin >> n;

	REP(n)
	{
		rep(j, 10)
		{
			rep(k, 10)
			{
				cin >> tile[j][k];
			}
		}

		for (int j=0; j<(1<<10); j++)
		{
			memset(flip, 0, sizeof(flip));
			for (int k=0; k<10; k++)
			{
				flip[0][10-k-1] = j >> k & 1;
			}
			
			if (calc())
			{
				print();
				break;
			}
		}

		/*
		//デバッグ
		rep(j, 10)
		{
			rep(k, 10)
			{
				printf("%d ", tile[j][k]);	
			}
			printf("\n");
		}
		*/
	}

    return 0;
}
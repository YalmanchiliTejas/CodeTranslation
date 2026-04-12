#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define pb push_back
#define fs first
#define sc second
#define openfile {freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
#define debug 0

struct card
{
	char x, y;

	bool operator > (const card &a)
	{
		if (y != a.y)
		{
			if (a.y == 'S' && (y == 'H' || y == 'D' || y == 'C')) return true;
			if (a.y == 'H' && (y == 'D' || y == 'C')) return true;
			if (a.y == 'D' && y == 'C') return true;
			return false;
		}
		if (a.x <= '9' && x > a.x) return true;
		if (a.x == 'T' && (x == 'J' || x == 'Q' || x == 'K' || x == 'A')) return true;
		if (a.x == 'J' && (x == 'Q' || x == 'K' || x == 'A')) return true;
		if (a.x == 'Q' && (x == 'K' || x == 'A')) return true;
		if (a.x == 'K' && x == 'A') return true;
		return false;
	}
};

card a[5][20];
char trumph;

void inputFile()
{
	for (int k = 1; k <= 4; k++)
	for (int i = 1; i <= 13; i++)
	{
		char x;
		scanf("%c%c%c", &a[k][i].x, &a[k][i].y, &x);
	}
}

void solve()
{
	int turn = 1;
	int EW = 0, NS = 0;
	for (int i = 1; i <= 13; i++)
	{
		card maxx = a[1][i];
		int x = 1;
		for (int j = 2; j <= 4; j++)
			if (a[j][i].y == trumph)
			{
				if (maxx.y != trumph || a[j][i] > maxx)
				{
					maxx = a[j][i];
					x = j;
				}
			}
		if (maxx.y == trumph)
		{
			if (x == 1 || x == 3) NS++;
			else EW++;
			turn = x;
			continue;
		}

		maxx = a[turn][i];
		x = turn;
		for (int j = 1; j <= 4; j++)
			if (j != turn && a[j][i].y == a[turn][i].y && a[j][i] > maxx)
			{
				maxx = a[j][i];
				x = j;
			}
		if (x == 1 || x == 3) NS++;
		else EW++;
		turn = x;
	}
	if (EW > NS) printf("EW %d\n", EW-6);
	else printf("NS %d\n", NS-6);
}

int main()
{
   if (debug) openfile;

   while (scanf("%c\n", &trumph) && trumph != '#')
   {
		inputFile();
		solve();
   }

   return 0;
}
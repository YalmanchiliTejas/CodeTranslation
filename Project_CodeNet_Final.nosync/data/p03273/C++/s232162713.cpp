#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#define REP(i, n) for(int i=0; i<n; i++)
#define REPR(i, n) for(int i=n; i>=0; i--)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORR(i, m, n) for(int i=m; i>=n; i--)
#define INF 999999999
#define ll long long
#define VSORT(v) sort(v.begin(), v.end())
#define pb(a) push_back(a)
using namespace std;

#ifdef INPUT
#include <sstream>
stringstream input(R"(
7 6
......
....#.
.#....
..#...
..#...
......
.#..#.
)");
#define cin input
#endif

int main()
{
	int h, w;
	cin >> h >> w;

	char a[h][w];
	REP(i,h)
	{
		REP(j,w)
			cin >> a[i][j];
	}

	char s='T';
	REP(i,h)
	{
		REP(j,w)
		{
			if (a[i][j]=='#')
			{
				s = 'F';
				break;
			}
		}
		if(s=='T')
		{
			REP(j,w)
			{
				a[i][j]='N';
			}
		}
		s='T';
	}

	REP(i,w)
	{
		REP(j,h)
		{
			if(a[j][i]=='#')
			{
				s = 'F';
				break;
			}
		}
		if(s=='T')
		{
			REP(j,h)
			{
				a[j][i]='N';
			}
		}
		s='T';
	}

	REP(i,h)
	{
		REP(j,w)
		{
			if (a[i][j]!='N')
				cout << a[i][j];
		}
		cout << endl;
	}	
}
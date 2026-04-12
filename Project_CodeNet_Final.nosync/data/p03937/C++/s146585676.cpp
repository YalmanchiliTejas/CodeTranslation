//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector < string > s(n);
	vector < vector < bool > > was(n, vector < bool > (m));
	for (int i = 0; i < n; i++)
	{	
		cin >> s[i];
	}
	int x = 0, y = 0;
	if (s[0][0] != '#')
	{
		cout << "Impossible" << endl;
		return 0;
	}
	while(true)
	{
		was[x][y] = true;
		if (x < n - 1 && s[x + 1][y] == '#')
		{
			x++;
		}
		else if (y < m - 1&& s[x][y + 1] == '#')
			y++;
		else 
			break;
	}
	if (x != n - 1 || y != m - 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!was[i][j] && s[i][j] == '#')
			{
				 cout << "Impossible" << endl;
				 return 0;
			}
		}
	}
	cout << "Possible" << endl;

	return 0;
}


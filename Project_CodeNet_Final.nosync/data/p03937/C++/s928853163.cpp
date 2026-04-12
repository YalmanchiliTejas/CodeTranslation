#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (1 << 10);

int n, m;
string t[MAXN];

void read()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> t[i];
}

bool ok[MAXN][MAXN];

void solve()
{
	int pos_x = 0, pos_y = 0;
	while(pos_x != n - 1 || pos_y != m - 1)
	{
		if(t[pos_x][pos_y] != '#') 
		{
			cout << "Impossible" << endl;
			return;
		}

		ok[pos_x][pos_y] = 1;
		if(pos_x != n - 1 && t[pos_x + 1][pos_y] == '#')
		{
			pos_x++;
			continue;
		}

		if(pos_y != m - 1 && t[pos_x][pos_y + 1] == '#')
		{
			pos_y++;
			continue;
		}

		cout << "Impossible" << endl;
		return;
	}

	if(t[n - 1][m - 1] != '#') 
	{
		cout << "Impossible" << endl;
		return;

	}
	else ok[n - 1][m - 1] = 1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!ok[i][j] && t[i][j] == '#')
			{
				cout << "Impossible" << endl;
				return;
			}

	cout << "Possible" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}


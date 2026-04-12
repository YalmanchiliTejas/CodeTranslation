#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n, m, d[N][N], f[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> d[i][j];
	for(int x = 1; x <= n; x++)
		for(int y = 1; y <= m; y++)
			for(int i = 0; i <= 100; i++)
				for(int j = 0; j <= 100; j++)
					f[i][j] = max(f[i][j], d[x][y] - i * x - j * y);
	for(int x = 1; x <= n; x++)
		for(int y = 1; y <= m; y++)
		{
			int dist = INT_MAX;
			for(int i = 0; i <= 100; i++)
				for(int j = 0; j <= 100; j++)
					dist = min(dist, f[i][j] + i * x + j * y);
			if(d[x][y] != dist) return (cout << "Impossible" << endl) && 0; 
		}
	cout << "Possible" << endl;
	cout << "202 10401" << endl;
	for(int i = 1; i < 101; i++) cout << i << ' ' << i + 1 << ' ' << 'X' << endl;
	for(int i = 102; i < 202; i++) cout << i << ' ' << i + 1 << ' ' << 'Y' << endl;
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			cout << i + 1 << ' ' << 202 - j << ' ' << f[i][j] << endl;
	cout << "1 202" << endl;
	return 0;
}
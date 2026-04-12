#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 15, INF = 1e9 + 5;

int main()
{
	int n, m;
	cin >> n >> m;

	char a[N][N];
	// bool mark[N][N] = {0};
	int ways[N][N] = {0};

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	ways[1][1] = 1;
	int ctr = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] == '#')
				++ctr;

			if (i == 1 and j == 1)
				continue;

			if (a[i][j] == '.')
				continue;

			ways[i][j] = ways[i-1][j] + ways[i][j-1];
		}
	}

	if (ways[n][m] and ctr == n+m-1)
		cout << "Possible";

	else
		cout << "Impossible";

	// int i = 1, j = 1;

	// if (a[i][j] == '.')
	// {
	// 	cout << "Impossible";
	// 	return 0;
	// }

	// mark[i][j] = true;

	// while (i != n or j != m)
	// {
	// 	if (i == n)
	// 	{
	// 		if (a[i][j+1] == '.')
	// 		{
	// 			cout << "Impossible";
	// 			return 0;
	// 		}

	// 		++j;
	// 		mark[i][j] = true;
	// 	}

	// 	else if (j == m)
	// 	{
	// 		if (a[i+1][j] == '.')
	// 		{
	// 			cout << "Impossible";
	// 			return 0;
	// 		}

	// 		++i;
	// 		mark[i][j] == true;
	// 	}

	// 	else if (a[i+1][j] == a[i][j+1])
	// 	{
	// 		cout << "Impossible";
	// 		return 0;
	// 	}

	// 	else if (a[i+1][j] == '#')
	// 	{
	// 		++i;
	// 		mark[i][j] = true;
	// 	}

	// 	else
	// 	{
	// 		++j;
	// 		mark[i][j] = true;
	// 	}
	// }

	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 1; j <= m; ++j)
	// 	{
	// 		if (a[i][j] == '#' and !mark[i][j])
	// 		{
	// 			cout << "Impossible";
	// 			return 0;
	// 		}
	// 	}
	// }

	// cout << "Possible";
}
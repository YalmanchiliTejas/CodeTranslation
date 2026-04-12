#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> matrix(n, vector<char>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}

	vector<int> emptyRows(n);
	for (int i = 0; i < n; i++)
	{
		bool isPossible = true;
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == '#')
			{
				isPossible = false;
				break;
			}
		}
		if (isPossible)
		{
			emptyRows[i] = 1;
		}
	}

	vector<int> emptyCols(m);
	for (int j = 0; j < m; j++)
	{
		bool isPossible = true;
		for (int i = 0; i < n; i++)
		{
			if (matrix[i][j] == '#')
			{
				isPossible = false;
				break;
			}
		}

		if (isPossible)
		{
			emptyCols[j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (emptyRows[i])
		{
			continue;
		}

		for (int j = 0; j < m; j++)
		{
			if (!emptyCols[j])
			{
				cout << matrix[i][j];
			}
		}
		cout << endl;
	}
}
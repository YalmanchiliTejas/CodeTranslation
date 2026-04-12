// template.cpp

// Defines.
//#define DEBUG
#define NUMBER_OF_DIGITS 12

// Includes.
#include <bits/stdc++.h>

#ifdef DEBUG
#include <chrono>
#endif

// Usings.
using namespace std;

// Main function.
int main()
{
#ifdef DEBUG
	chrono::system_clock::time_point start, end;
	
	start = chrono::system_clock::now();
#endif
	
	// settings.
	ios::sync_with_stdio(false);
	
	cout << fixed;
	cout << setprecision(NUMBER_OF_DIGITS);
	
	// logic.
	int n, m;
	cin >> n >> m;
	
	bool sides[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sides[i][j] = false;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		sides[a - 1][b - 1] = true;
		sides[b - 1][a - 1] = true;
	}
	
	vector<int> vertexes;
	for (int i = 0; i < n; i++)
	{
		vertexes.push_back(i);
	}
	
	int counter = 0;
	do
	{
		if (vertexes[0] != 0)
		{
			continue;
		}
		
		bool flag = true;
		for (int i = 0; i < (n - 1); i++)
		{
			if (sides[vertexes[i]][vertexes[i + 1]] == false)
			{
				flag = false;
				break;
			}
		}
		
		if (flag == true)
		{
			counter++;
		}
	}
	while (next_permutation(vertexes.begin(), vertexes.end()));
	
	cout << counter << endl;

#ifdef DEBUG
	end = chrono::system_clock::now();
	
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	cout << elapsed << "[ms]" << endl;
#endif
	
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void solve()
{
	int n;
	while(cin >> n, n)
	{
		vector< vector<int> > Vec(n, vector<int>(n));
		int x = n / 2;
		int y = n / 2;
		++y;
		int count = 1;
		Vec[y][x] = count;
		int square = n * n;
		while(count < square)
		{
			++count;
			++x;
			++y;
			if(x >= n)
			{
				x = 0;
			}
			if(y >= n)
			{
				y = 0;
			}
			while(Vec[y][x] != 0)
			{
				--x;
				++y;
				if(x < 0)
				{
					x = n - 1;
				}
				if(y >= n)
				{
					y = 0;
				}
			}
			Vec[y][x] = count;
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				printf("%4d", Vec[i][j]);
			}
			cout << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}
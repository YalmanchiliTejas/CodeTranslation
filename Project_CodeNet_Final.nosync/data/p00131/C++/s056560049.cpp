#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <complex>


typedef long long ll;
const double Eps = 1e-5;

using namespace std;

int state[10][10];
int fired[10][10];

void fire(int x, int y)
{
	int dx[] = { 0, 0, 1, 0, -1 };
	int dy[] = { 0, -1, 0, 1, 0 };
	for (int i = 0; i < 5; ++i)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (0 <= tx && tx < 10
			&& 0 <= ty && ty < 10)
		{
			state[ty][tx] = state[ty][tx] ? 0 : 1;
		}
	}
	fired[y][x] = 1;
}
bool is_alloff()
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if (state[i][j])
				return false;
	return true;
}
void print_state(int s[10][10])
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 9; ++j)
			printf("%d ", s[i][j]);
		printf("%d\n", s[i][9]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int defState[10][10];
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				int t;
				scanf("%d", &t);
				defState[i][j] = t;
			}
		}

		for (int subset = 0; subset < 1 << 10; ++subset)
		{
			memcpy(state, defState, sizeof(state));
			memset(fired, 0, sizeof(fired));

			for (int i = 0; i < 10; ++i)
				if (subset & 1 << i)
					fire(i, 0);

			for (int i = 1; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (state[i-1][j])
						fire(j, i);
				}
			}

			if (is_alloff())
				break;
		}
		print_state(fired);
	}

	return 0;
}
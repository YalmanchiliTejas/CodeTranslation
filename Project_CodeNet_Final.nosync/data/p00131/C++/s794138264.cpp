#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstring>
#include<stack>
#include<functional>
#include<sstream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
int dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1};
int fld[10][10];

void Reverse(int x, int y, int cnt[10][10])
{
	for(int i = 0; i < 5; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < 10 && 0 <= ny && ny < 10) cnt[ny][nx]++;
	}
}

int main(){
	int N;
	cin >> N;
	for(int c = 0; c < N; c++)
	{
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				cin >> fld[i][j];
			}
		}

		bool ans = false;
		int out[10][10];
		for(int p = 0; p < (1 << 10); p++)
		{
			int cnt[10][10] = {};
			for(int i = 0; i < 10; i++)
			{
				out[0][i] = ((p >> i) & 1);
				if(out[0][i] == 1) Reverse(i, 0, cnt);
			}
			for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 10; j++)
				{
					if(((fld[i][j] + cnt[i][j]) & 1) == 1)
					{
						out[i + 1][j] = 1;
						Reverse(j, i + 1, cnt);
					}
					else
					{
						out[i + 1][j] = 0;
					}
				}
			}

			ans = true;
			for(int i = 0; i < 10; i++)
			{
				if(((fld[9][i] + cnt[9][i]) & 1) == 1) ans = false;
			}
			if(ans) break;
		}

		for(int i = 0; i < 10; i++)
		{
			printf("%d", out[i][0]);
			for(int j = 1; j < 10; j++)
			{
				printf(" %d", out[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
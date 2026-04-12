#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int f[10][10];
int temp[10][10];
int ans[10][10];
int dx[5] = {1,0,0,-1,0};
int dy[5] = {0,1,0,0,-1};

void change(int y,int x)
{
	if(f[y-1][x] == 1)
	{
		ans[y][x] = 1;
		rep(i,5)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(0 <= nx && nx < 10 && 0 <= ny && ny < 10)
			{
				f[ny][nx] = !f[ny][nx];			
			}
		}
	}
}

bool check(int *used)
{
	memset(ans,0,sizeof(ans));
	memcpy(f,temp,sizeof(temp));

	rep(i,10)
	{
		ans[0][i] = used[i];
		if(used[i])
		{
			rep(j,5)
			{
				int nx = i + dx[j];
				int ny = dy[j];

				if(0 <= nx && nx < 10 && 0 <= ny && ny < 10)
				{
						f[ny][nx] = !f[ny][nx];
				}
			}
		}
	}

	REP(i,1,10)
	{
		rep(j,10)
		{
			change(i,j);	
		}
	}

	int cnt = 0;
	rep(i,10) rep(j,10) if(f[i][j] == 1) cnt++;

	if(cnt == 0)
	{
		return true;
	}
	else return false;
}

bool dfs(int i,int *t)
{
	if(i == 10)
	{
		if(check(t)) return true;
		else return false;
	}

	if(dfs(i+1,t)) return true;
	t[i] = 1;
	if(dfs(i+1,t)) return true;
	t[i] = 0;
}

int main()
{
	int n;
	cin >> n;

	rep(i,n)
	{
		memset(f,0,sizeof(f));
		memset(temp,0,sizeof(temp));

		rep(j,10)
		{
			rep(k,10)
			{
				cin >> temp[j][k];
			}
		}
		
		int t[10];
		memset(t,0,sizeof(t));
		dfs(0,t);
	

		rep(j,10)
		{
			rep(k,10)
			{
				cout << ans[j][k];

				if(k == 9) cout << endl;
				else cout << " ";
			}
		}
	}
	return 0;
}
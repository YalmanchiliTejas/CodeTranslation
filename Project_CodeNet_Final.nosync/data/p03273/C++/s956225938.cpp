#include <bits/stdc++.h>

using namespace std;

char board[100][100];
bool iserase[100][100];
int h,w;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	memset(iserase,false,sizeof(iserase));

	cin >> h >> w;

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> board[i][j];
		}
	}

	for(int i=0;i<h;i++)
	{
		bool ok = true;
		for(int j=0;j<w;j++)
		{
			if(board[i][j]=='#')
			{
				ok = false;
				break;
			}
		}
		if(ok)
		{
			for(int j=0;j<w;j++)
			{
				iserase[i][j] = true;
			}
		}
	}

	for(int j=0;j<w;j++)
	{
		bool ok = true;
		for(int i=0;i<h;i++)
		{
			if(board[i][j]=='#')
			{
				ok = false;
				break;
			}
		}
		if(ok)
		{
			for(int i=0;i<h;i++)
			{
				iserase[i][j] = true;
			}
		}
	}	

	for(int i=0;i<h;i++)
	{
		bool flag = false;
		for(int j=0;j<w;j++)
		{
			if(iserase[i][j]==false)
			{
				flag = true;
				cout << board[i][j];
			}
		}
		if(flag)
		{
			cout << '\n';
		}
	}

	return 0;
}
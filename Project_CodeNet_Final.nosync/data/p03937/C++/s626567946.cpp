#include <bits/stdc++.h>
using namespace std;
int h,w;
int dr[] = {0,1}, dc[] = {1,0};
string board[10];
bool ok(int r, int c)
{
	if(0 <= r && r < h && 0 <= c && c < w)
		return true;
	return false;
}
int main()
{
	cin>>h>>w;
	for (int i = 0; i < h; ++i)
	{
		cin>>board[i];
	}
	int pr = 0, pc = 0;
	bool flag = true;
	while(flag)
	{
		flag = false;
		board[pr][pc] = '.';
		for (int i = 0; i < 2; ++i)
		{
			int nr = pr + dr[i], nc = pc + dc[i];
			if(ok(nr,nc) && board[nr][nc] == '#')
			{
				pr = nr;
				pc = nc;
				flag = true;
				break;
			}
		}
	}
	if(pr == h-1 && pc == w-1)
	{
		bool ans = true;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				ans = (ans && (board[i][j] == '.'));
			}
		}
		if(ans)
			cout<<"Possible\n";
		else
			cout<<"Impossible\n";
	}
	else
		cout<<"Impossible\n";
	return 0;
}
#include <iostream>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int field[16][16];
	int n;
	while(cin >> n && n)
	{
		memset(field,0,sizeof(field));

		int x = n/2;
		int y = n/2 + 1;
		field[y][x] = 1;

		int count = 2;
		while(true)
		{
			if(count >  n*n)
			{
				break;
			}

			x += 1;
			y += 1;

			if(x >= n)
			{
				x = 0;
			}
			if(x < 0)
			{
				x = n-1;
			}
			if(y >= n)
			{
				y = 0;
			}
			if(y < 0)
			{
				y = n-1;
			}
			if(field[y][x] == 0)
			{
				field[y][x] = count;
				count++;
			}
			else
			{
				x -= 2;
			}
		}

		rep(i,n)
		{
			rep(j,n)
			{
				cout.width(4);
				cout << field[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
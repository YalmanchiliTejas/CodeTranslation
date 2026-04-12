#include <iostream>
#include <cstring>
using namespace std;

int n,s,y,x,i;
int d[12][12],b[12][12],a[12][12];
int dx[] = { 0,0,0,1,-1};
int dy[] = {-1,1,0,0, 0};

void flip(int x, int y)
{
	a[y][x] = 1;
	for(int i=0; i<5; i++)
	{
		b[y+dy[i]][x+dx[i]] = 1-b[y+dy[i]][x+dx[i]];
	}
}

int main()
{
	cin >> n;
	while(n--)
	{
		for(y=1; y<=10; y++)
		for(x=1; x<=10; x++)
		{
			cin >> d[y][x];
		}
		for(i=0; i<1024; i++)
		{
			memset(a,0,sizeof(a));
			memcpy(b,d,sizeof(d));

			for(y=1,x=1; x<=10; x++)
			{
				if((i>>(x-1))&1) flip(x,y);
			}

			for(y=2; y<=10; y++)
			for(x=1; x<=10; x++)
			{
				if(b[y-1][x]) flip(x,y);
			}

			for(y=10,x=1,s=0; x<=10; x++)
			{
				s+=b[y][x];
			}

			if(s==0) break;
		}

		for(y=1; y<=10; y++)
		{
			for(x=1; x<=10; x++)
			{
				cout << a[y][x] << (x==10?"":" ");
			}
			cout << endl;
		}
	}
}
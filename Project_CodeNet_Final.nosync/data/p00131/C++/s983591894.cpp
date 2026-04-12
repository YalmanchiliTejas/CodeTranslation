#include <iostream>
#include <cstring>
using namespace std;

int n,s,d[12][12],b[12][12],a[12][12];
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

void func()
{
	for(int i=0; i<1024; i++)
	{
		memset(a,0,sizeof(a));
		memcpy(b,d,sizeof(d));

		for(int y=1,x=1; x<=10; x++)
		{
			if((i>>(x-1))&1) flip(x,y);
		}

		for(int y=2; y<=10; y++)
		for(int x=1; x<=10; x++)
		{
			if(b[y-1][x]) flip(x,y);
		}

		s=0;
		for(int y=10,x=1; x<=10; x++)
		{
			s+=b[y][x];
		}

		if(s==0) return;
	}
}

int main()
{
	cin >> n;
	while(n--)
	{
		for(int y=1; y<=10; y++)
		for(int x=1; x<=10; x++)
		{
			cin >> d[y][x];
		}

		func();

		for(int y=1; y<=10; y++)
		{
			for(int x=1; x<=10; x++)
			{
				cout << a[y][x] << (x==10?"":" ");
			}
			cout << endl;
		}
	}
}
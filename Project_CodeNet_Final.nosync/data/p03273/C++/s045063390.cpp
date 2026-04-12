#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int h,w;
	cin>>h>>w;
	char a[h][w];
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin>>a[i][j];
		}
	}	
	for (int i = 0; i < h; ++i)
	{
		int f=1;
		for (int j = 0; j < w; ++j)
		{
			if (a[i][j]=='#')
			{
				f=0;
				break;
			}
		}
		if (f)
		{
			--h;
			for (int j = i; j < h; ++j)
			{
				for (int k = 0; k < w; ++k)
				{
					a[j][k]=a[j+1][k];
				}
			}
			--i;
		}
	}	
	for (int i = 0; i < w; ++i)
	{
		int f=1;
		for (int j = 0; j < h; ++j)
		{
			if (a[j][i]=='#')
			{
				f=0;
				break;
			}
		}
		if (f)
		{
			--w;
			for (int j = i; j < w; ++j)
			{
				for (int k = 0; k < h; ++k)
				{
					a[k][j]=a[k][j+1];
				}
			}
			--i;
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}

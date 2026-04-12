#include <bits/stdc++.h>
using namespace std;
int main()
{
	int w,h;
	cin>>w>>h;
	char g[w][h];
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
				cin>>g[i][j];
	int row_present[w]={0};
	int col_present[h]={0};

	for(int i=0;i<w;i++)
	{
		int c=0;
		for(int j=0;j<h;j++)
		{
			if(g[i][j]=='.')
				c++;
		}
		if(c==h) row_present[i]++;
	}
	for(int i=0;i<h;i++)
	{
		int c=0;
		for(int j=0;j<w;j++)
		{
			if(g[j][i]=='.')
				c++;
		}
		if(c==w) col_present[i]++;
	}
	for(int i=0;i<w;i++)
	{
		if(row_present[i]==0)
		{
			for(int j=0;j<h;j++)
			{	
				if(col_present[j]==0)
					cout<<g[i][j];
			}
			cout<<endl;
		}
		
	}
	return 0;
}

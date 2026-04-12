#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
	int x,y;
	while(cin>>x>>y)
	{
		string s[105];
		for(int i=0;i<x;)
		{
			cin>>s[i];
			getchar();
			int k=0;
			for(int j=0;j<y;j++)
				if(s[i][j]=='.')
					k++;
			if(k!=y)
				i++;
			else
				x--;	
		}
		for(int j=0;j<y;j++)
		{
			int k=0;
			for(int i=0;i<x;i++)
				if(s[i][j]=='.')
					k++;
			if(k==x)
			{
				for(int i=0;i<x;i++)
					s[i][j]=' ';
			}
		}
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
				if(s[i][j]!=' ')
					cout<<s[i][j];
			printf("\n");
		}
	}
	return 0;
}
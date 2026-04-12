#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 10

using namespace std;

char mp[SIZE][SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	int px=0,py=0;
	while(1)
	{
		mp[px][py]='.';
		if(px+1<n&&mp[px+1][py]=='#') px++;
		else if(py+1<m&&mp[px][py+1]=='#') py++;
		else break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]!='.')
			{
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");
	return 0;
}

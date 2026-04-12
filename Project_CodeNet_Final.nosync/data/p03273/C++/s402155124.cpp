#include <cstdio>
using namespace std;
int h,w;
char c[100][100];
bool isw[100];
int main()
{
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++)
	{
		bool tf=false;
		for(int j=0;j<w;j++)
		{
			scanf(" %c",&c[i][j]);
			if(!tf || !isw[j])
				if(c[i][j]=='#')
					tf=isw[j]=true;
		}
		if(!tf)
		{
			i--;
			h--;
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			if(isw[j])
				printf("%c",c[i][j]);
		printf("\n");
	}
	return 0;
}
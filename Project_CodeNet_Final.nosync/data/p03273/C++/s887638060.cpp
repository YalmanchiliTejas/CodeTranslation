#include<cstdio>
using namespace std;
int H,W;
char a[101][102];
bool pdh[101],pdl[101];
int main()
{
	scanf("%d%d",&H,&W);
	for (int i=1;i<=H;i++)
	{
		for (int k=1;k<=W;k++)
		{
			scanf(" %c",&a[i][k]);
			if (a[i][k]=='#')
			{
				pdh[i]=true;
				pdl[k]=true;
			}
		}
	}
	for (int i=1;i<=H;i++)
	{
		if (pdh[i])
		{
			for (int k=1;k<=W;k++)
			{
				if (pdl[k]) printf("%c",a[i][k]);
			}
			printf("\n");
		}
	}
	return 0;
}
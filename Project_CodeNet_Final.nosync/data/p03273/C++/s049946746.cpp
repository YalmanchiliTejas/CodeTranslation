#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
int main(void)
{
	int h,w,i,j,fh[100],fw[100];
	char a[100][101];
	scanf("%d %d",&h,&w);
	for(i=0;i<h;i++)	scanf("%s",a[i]);
	for(i=0;i<h;i++)	{
		fh[i]=0;
		for(j=0;j<w;j++)	{
			if(a[i][j]=='#')	{
				fh[i]=1;	break;
			}
		}
	}
	for(j=0;j<w;j++)	{
		fw[j]=0;
		for(i=0;i<h;i++)	{
			if(a[i][j]=='#')	{
				fw[j]=1;	break;
			}
		}
	}
	for(i=0;i<h;i++)	{
		if(fh[i]==1)	{
			for(j=0;j<w;j++)	{
				if(fw[j]==1)	{
					printf("%c",a[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
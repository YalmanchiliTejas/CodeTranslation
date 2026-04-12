#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int h,w,f;
char a[10][10];
bool vis[10][10];
int main()
{
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++)
	{
		scanf("%s",a[i]);
		for(int j=0;j<w;j++)
			f+=(a[i][j]=='#');
	}
	if(f==h+w-1)printf("Possible");
	else printf("Impossible");
}
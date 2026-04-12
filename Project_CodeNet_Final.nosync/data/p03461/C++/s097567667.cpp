#include<cstdio>
#include<iostream>
using namespace std;
int d[11][11],n,m,tot,now,sum;
int pa[110],pb[110];
bool vis[11][11];
struct edg{
	int a,b,c;
}ans[310];
void print()
{
	//for (int i=1;i<=sum;i++)
	//	printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
	
	int numn=0,numm=0;
	for (int i=1;i<=sum;i++)
	{
		numm+=ans[i].a+ans[i].b+1;
		numn+=ans[i].a+ans[i].b;
	}
	numn+=2;
	if (numn>300) {while(1);printf("Impossible\n");return;}
	printf("Possible\n");
	printf("%d %d\n",numn,numm);
	int t=1,pre=1;
	for (int i=1;i<=sum;i++)
	{
		pre=1;
		printf("%d %d %d\n",pre,++t,ans[i].c),pre=t;
		for (int j=1;j<=ans[i].a;j++)
		{
			printf("%d %d %c\n",pre,(j==ans[i].a&&ans[i].b==0)?numn:++t,'X'),pre=t;
		}
		for (int j=1;j<=ans[i].b;j++)
			printf("%d %d %c\n",pre,(j==ans[i].b)?numn:++t,'Y'),pre=t;
		
	}
	printf("%d %d\n",1,numn);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&d[i][j]);
	for (int s=0;s<=300;s++)
		for (int a=0;a<=s&&a<=100;a++)
			for (int b=0;b<=s-a&&b<=100;b++)
				{
					int c=s-a-b;
					bool p=0,q=0;
					int now=0;
					for (int i=1;i<=n;i++)
					{
						for (int j=1;j<=m;j++)
						{
							if (a*i+b*j+c==d[i][j]&&!vis[i][j]) q=1,now++,pa[now]=i,pb[now]=j;
							else if (a*i+b*j+c<d[i][j]) {p=1;break;}
						}
						if (p==1) break;
					}
					if ((!p)&&q) 
					{
						//cout<<now<<endl;
						for (int i=1;i<=now;i++)
							vis[pa[i]][pb[i]]=1;
						tot+=now,ans[++sum].a=a,ans[sum].b=b,ans[sum].c=c;
						if (tot==n*m){print();return 0;}
					}
				}
	printf("Impossible\n");
}
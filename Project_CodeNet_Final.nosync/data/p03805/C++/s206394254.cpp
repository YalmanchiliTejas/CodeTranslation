#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
void func(int,int);
int n,m,a[9][8],cnt[9],sum,flg[9];
int main(void)
{
	int i,j,x,y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)	cnt[i]=0;
	for(i=0;i<m;i++)	{
		scanf("%d %d",&x,&y);
		a[x][cnt[x]]=y;
		cnt[x]++;
		a[y][cnt[y]]=x;
		cnt[y]++;
	}
	sum=0;
	for(i=1;i<=n;i++)	flg[i]=0;
	flg[1]=1;
	func(1,1);
	printf("%d\n",sum);
	return 0;
}
void func(int xx,int nn)
{
	int i,x2;
//	printf("xx=%d nn=%d\n",xx,nn);
	if(nn==n)	{
		sum++;
	}
	else {
		for(i=0;i<cnt[xx];i++)	{
			x2=a[xx][i];
			if(flg[x2]==0)	{
				flg[x2]=1;
				func(x2,nn+1);
				flg[x2]=0;
			}
		}
	}
}
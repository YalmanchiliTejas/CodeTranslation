#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define regsiter register
#define CL fclose(stdin),fclose(stdout)
namespace io
{
	int F()
	{
		int n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
	long long G()
	{
		long long n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
}
int d[15][15];
int li[222][222];
int dis[222]; 
int main()
{
	int a=io::F(),b=io::F();
	for(register int i=1;i<=a;++i)
		for(register int j=1;j<=b;++j)
			d[i][j]=io::F();
	int po=202;
	for(register int i=1;i<=po;++i)
		for(register int j=1;j<=po;++j)
			li[i][j]=-3;
	int pe=0;
	for(register int i=1;i<=100;++i)li[i][i+1]=-1,++pe;
	for(register int i=202;i>102;--i)li[i][i-1]=-2,++pe;
	int s=1,t=102;
	for(register int i=0;i<=100;++i)
		for(register int j=0;j<=100;++j)
		{
			int max=0;
			for(register int x=1;x<=a;++x)
				for(register int y=1;y<=b;++y)
					cmax(max,d[x][y]-i*x-j*y);
			li[s+i][t+j]=max;
			++pe;
		}
	for(register int x=1;x<=a;++x)
		for(register int y=1;y<=b;++y)
		{
			memset(dis,63,sizeof(dis));
			dis[1]=0;
			for(register int i=1;i<=100;++i)dis[i+1]=dis[i]+x;
			for(register int i=1;i<=101;++i)
				for(register int j=102;j<=202;++j)
					if(li[i][j]!=-3)cmin(dis[j],dis[i]+li[i][j]);
			for(register int i=202;i>t;--i)
				cmin(dis[i-1],dis[i]+y);
			if(dis[t]!=d[x][y])
			{
				puts("Impossible");
				return 0;
			}
		}
	puts("Possible");
	printf("%d %d\n",po,pe);
	for(register int i=1;i<=po;++i)
		for(register int j=1;j<=po;++j)
		{
			if(li[i][j]==-1)printf("%d %d X\n",i,j);
				else if(li[i][j]==-2)printf("%d %d Y\n",i,j);
						else if(li[i][j]!=-3)printf("%d %d %d\n",i,j,li[i][j]);
		}
	printf("%d %d\n",s,t);
	return 0;
}



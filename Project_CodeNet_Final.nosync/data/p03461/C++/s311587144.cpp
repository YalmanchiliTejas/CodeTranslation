#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
const int N=105;
int c[N][N],d[15][15];
bool judge(int a,int b)
{
    int i,j,k,l;
    for(i=1;i<=a;i++)
        for(j=1;j<=b;j++)
	{
            int dist=1e9;
            for(k=0;k<=100;k++)
                for(l=0;l<=100;l++)
                    dist=min(dist,i*k+j*l+c[k][l]);
            if(dist!=d[i][j]) return 0;
        }
    return 1;
}
int main()
{
    int a,b,i,j,k,l;
    a=ri(),b=ri();
    for(i=1;i<=a;i++)
        for(j=1;j<=b;j++)
            d[i][j]=ri();
    for(i=1;i<=a;i++) 
        for(j=1;j<=b;j++) 
            for(k=0;k<=100;k++) 
                for(l=0;l<=100;l++)
                    c[k][l]=max(c[k][l],d[i][j]-i*k-j*l);
    if(judge(a,b))
    {
        puts("Possible");
        printf("%d %d\n",202,101*101+200);
        for(i=1;i<=100;i++)
	    printf("%d %d X\n",i,i+1);
        for(i=102;i<202;i++)
	    printf("%d %d Y\n",i+1,i);
        for(i=0;i<=100;i++)
            for(j=0;j<=100;j++)
		printf("%d %d %d\n",i+1,j+102,c[i][j]);
        printf("%d %d\n",1,102);
    }
    else	puts("Impossible");
    return 0;
}
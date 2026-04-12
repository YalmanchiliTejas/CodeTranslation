#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<iostream>
#define ll long long
using namespace std;
#define max(a,b)    (a)>(b)?(a):(b)
#define min(a,b)    (a)<(b)?(a):(b)
#define s(i)        scanf("%d",&(i))
#define ss(i)       scanf("%s",(i))
#define p(i)        printf("%d",i)
#define ps(i)       printf("%s",(i))
#define pc(i)       printf("%c",(i))
#define end         printf("\n")
#define f(i,n)      for(i=1;i<=n;i++)
#define w(i)        while(i--)
#define m(vis)      memset(vis,0,sizeof vis);
int a[200001];
int b[200001];
int main()
{
	int i,n,j;
	scanf("%d",&n);
	f(i,n)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int x=b[n/2];
	f(i,n)
	{
		if(a[i]>x)
			p(x);
		else
			p(b[n/2+1]);
		end;
	}
    return 0;
}
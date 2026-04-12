#include<bits/stdc++.h>
#define L long long
using namespace std;
int t,n,m;
L p;
inline L calc(int a,int b,int c)
{
    if(a>m)
      return (L)(b+1)*m;
    int k=min((m-a)/c,b);
    return (L)a*(k+1)+(L)c*(k+1)*k/2+(L)(b-k)*m;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	//scanf("%d",&t);
	t=1;
	while(t--)
	  {
	   scanf("%d%d",&n,&m);
	   if(!m)
	     {
          printf("%lld\n",(L)n*n);
          continue;
         }
	   m--;
	   p=(L)(m+1)*n;
	   for(i=m+2;i<=n;i=j+1)
	     {
          k=n/i;
          j=n/k;
          p+=(L)(j-i+1)*k*(m+1)+calc(n-j*k,j-i,k);
         }
       p=(L)n*n-p;
       printf("%lld\n",p);
      }
	return 0;
}

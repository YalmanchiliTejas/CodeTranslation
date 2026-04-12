#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
inline long long read()
{
   long long sum=0,x=1;
   char ch=getchar();
   while (ch<'0'||ch>'9')
   {
       if (ch=='-')
	     x=-1;
	   ch=getchar();
   }
   while (ch>='0'&&ch<='9')
   {
   	   sum=sum*10+ch-'0';
	   ch=getchar();
   }
   return sum*x;
}
inline void write(long long x)
{
    if (x<0)
	{
        putchar('-');
        x=-x;
    }
    if (x>9)
      write(x/10);
    putchar(x%10+'0');
    return;
}
int main()
{
    n=read();k=read();
    if (k==0)
      write(n*n);else
    {
    	for (register int i=k+1;i<=n;++i)
        {
            ans=ans+(i-k)*(n/i);
            if (n%i-k>=0)
              ans=ans+1+n%i-k;
        }
	    write(ans);
	}
    return 0;
}
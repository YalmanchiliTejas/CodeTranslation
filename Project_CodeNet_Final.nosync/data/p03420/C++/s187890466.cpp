#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,i,j,k,s;
    scanf("%lld%lld",&n,&m);
    if(m==0)
    {
        printf("%lld\n",n*n);
        return 0;
    }
    s=0;
    for(i=m+1;i<=n;i++)
    {
        j=n/i;
        s=s+j*(i-m);
        k=n%i;
        s=s+max((long long)0,k-m+1);
    }
    printf("%lld\n",s);
    return 0;
}

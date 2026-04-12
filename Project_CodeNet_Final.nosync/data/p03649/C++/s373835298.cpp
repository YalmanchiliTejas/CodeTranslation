#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long a[55];
int main()
{
    long long x,s,sum,n,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sum=0;
    while(1)
    {
        sort(a,a+n);
        if(a[n-1]<n)
            break;
            s=a[n-1]/n;
        sum=sum+s;
        for(i=0;i<n-1;i++)
            a[i]=a[i]+s;
        a[n-1]=a[n-1]%n;
    }
    printf("%lld\n",sum);
    return 0;
}

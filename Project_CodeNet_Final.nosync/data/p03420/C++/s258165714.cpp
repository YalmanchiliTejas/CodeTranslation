#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    long long num=0;
    if(k==0)num=n*n;
    else
    {
        for(int b=k+1;b<=n;b++)
            /* (2,3),(5,3),(2,4),(3,4),(2,5),(3,5) and (4,5).*/
        {
            num+=(n/b)*(b-k);
            if(n%b>=k)num+=n%b-k+1;/*a%b取余只有当b>k时，才能余数>=k,*/
        }
    }
    printf("%lld\n",num);
    return 0;
}
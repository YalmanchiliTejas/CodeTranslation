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
        {
            num+=(n/b)*(b-k);
            if(n%b>=k)num+=n%b-k+1;
        }
    }
    printf("%lld\n",num);
    return 0;
}

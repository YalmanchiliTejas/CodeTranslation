#include<bits/stdc++.h>
long long a,b,k;
int main()
{
    scanf("%lld%lld%lld",&k,&a,&b);
    if(k<=a)puts("1"),exit(0);
    else if(a<=b)puts("-1"),exit(0);
    else printf("%lld\n",(k-b-1)/(a-b)<<1|1),exit(0);
}
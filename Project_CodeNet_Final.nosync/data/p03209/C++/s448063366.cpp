#include<bits/stdc++.h>
using namespace std;
long long  a[52],b[52];
long long x,n;
long long ans=0;
void f(int d)
{
    if(x==a[d]){ans+=b[d];return ;}
    else if(x)
    {
        x--;
        if(x>a[d-1])
        {
            x-=a[d-1];
            ans+=b[d-1];
            x--,ans++;
            if(x)f(d-1);
        }
        else f(d-1);
    }
}
int main()
{
    scanf("%lld%lld",&n,&x);
    a[0]=1,b[0]=1;
    for(int i=1; i<=50; i++)
    {
        a[i]=a[i-1]*2+3;
        b[i]=b[i-1]*2+1;
    }
    f(n);
    printf("%lld\n",ans);
}

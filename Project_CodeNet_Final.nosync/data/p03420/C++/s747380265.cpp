#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long ans = 0;
    for(int b=k+1;b<=n;b++)
    {
        long long t = n/b;
        ans += t*(b-k);
        t = n%b;
        if(t>=k) ans += t-k+1;
    }
    if(k == 0) ans -= n;
    printf("%lld\n",ans);
}

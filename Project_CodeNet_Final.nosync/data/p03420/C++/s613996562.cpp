#include <bits/stdc++.h>

using namespace std;

void action()
{
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long ans=0;
    if(k==0)
    {
        ans = n*n;
    }
    else
    {
        for(long long i=k+1; i<=n; i++)
        {
            long long nub_zu = n/i;
            long long sheng = n%i;
            if(sheng >= k)
                ans += (sheng-k+1);
            ans += nub_zu * (i-k);
        }
    }
    cout<<ans<<endl;

}
int main()
{
    action();
    return 0;
}


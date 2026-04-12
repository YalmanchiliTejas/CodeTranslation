#include <bits/stdc++.h>

using namespace std;


const long long MOD = 1000000007;

long long fastPower(long long exp, long long base)
{
    long long sol = 1;
    long long p=1;
    while(exp > 0)
    {
        if(exp & 1)  ///este echivalent cu exp % 2 == 1
            p = (p* (base%MOD))%MOD;
        base = ((base%MOD) * (base%MOD) )% MOD;
        exp = exp>>1; ///este echivalent cu p = p/2
    }
    return p;
}

int main()
{
    int n, i, j;
    long long x;
    cin>>n;
    long long sum = 0;
    long long sqsum = 0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        sum = (sum + x)%MOD;
        x = x * x;
        sqsum = (sqsum + x)%MOD;
    }
    sum = sum * sum;
    sum = (sum - sqsum)%MOD;
    long long sol = (sum * fastPower(MOD-2,2))%MOD;
    sol =sol % MOD;

    cout<<sol;


}

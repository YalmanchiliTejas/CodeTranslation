#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
#define mod 1000000007

long long power(long long  x, unsigned int y)
{
    long long  res = 1;     // Initialize result

    x = x % mod; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;
    }
    return res;
}
int main()
{

    int n;
    cin>>n;
    long long ans=0;
    long long temp;
    vector<long long> t;
    while(n--)
    {
        cin>>temp;
        t.push_back(temp);

    }
    long long sum[t.size()]={0};
    for(int i=t.size()-2;i>=0;i--)
    {
        sum[i]=(sum[i]+sum[i+1]+t[i+1])%mod;
    }
    for(int i=0;i<t.size();i++)
    {


            ans=(ans+(t[i]%mod*sum[i]%mod)%mod)%mod;
    }
    cout<<ans;
}

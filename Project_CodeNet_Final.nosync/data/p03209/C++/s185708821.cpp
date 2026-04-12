#include <cstdio>
#include <cmath>
#include <iostream>
 
using namespace std;
 
typedef  long long ll;
 
ll p[55], nlen[55];
 
ll solve(ll n, ll x)
{
    if(x <= n) return 0;
    nlen[n]=(1ll<<(n+2))-3;
    if(x >= nlen[n] - 1) return p[n];
    if(x == nlen[n] / 2 + 1) return (p[n] / 2 + 1);
    else if(x < nlen[n] / 2 + 1)
        return solve(n - 1, x - 1);
    else
        return p[n] / 2 + 1 + solve(n - 1, x - nlen[n] / 2 - 1);
}
 
int main()
{
    for(int i = 0; i <= 50; ++i)
    {
        p[i] = pow(2, i + 1) - 1;
       // nlen[i] = pow(2, i - 1) * 8 - 3;
    }
    ll n, x;
    cin>>n>>x;
    cout<<solve(n, x)<<endl;
    return 0;
}
//BISMILLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main()
{
    ll n,sum=0,ans=0;
    scanf("%lld",&n);
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
    }

    for(int i=0;i<n;i++)
    {
        ans=(ans+sum*v[i])%MOD;
        sum= (sum+v[i])%MOD; //prefix sum
    }

    printf("%lld\n",ans);

    return 0;
}
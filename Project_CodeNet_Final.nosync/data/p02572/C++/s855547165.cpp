#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    const int mod = 1e9 +7;
    ll n;

    cin>>n;
    vector<ll> a(n+3);

    rep(i,n)
    {
        cin>>a[i];
    }

    vector<ll> bu(n+3);
    
    bu[n-1] = a[n-1];

    for(ll i =n-2;i>=0;i--)
    {
        bu[i] = (bu[i+1]+a[i])%mod;
    }

    ll ans = 0;

    for(ll j=0;j<n-1;j++)
    {
        ans = (ans + a[j]*bu[j+1])%mod;

    }

    cout<<ans<<endl;

}
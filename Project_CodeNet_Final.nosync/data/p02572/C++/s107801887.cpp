#include<bits/stdc++.h>
using namespace std;
// -----------------<fast IO>------------------
#define IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FLSH             fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x)     cout << fixed << setprecision(x);
// -----------------<TypeDef Start>------------------
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
// -----------------<Constants>------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);

const int INF=1e9;

int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
/*ll gcd(ll a,ll b)
{
    if(a==0)
    return(b);
    return(gcd(b%a,a));
}*/
// --------------------------------------------------</TEMPLATE>--------------------------------------------------


void solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll s=0;
    for(ll i=0;i<n;i++)
        s+=arr[i];
    ll ans=0;
    for(ll i=0;i<n-1;i++)
    {
        s-=arr[i];
        ans=((ans)%MOD+((arr[i]%MOD)*(s%MOD))%MOD)%MOD;
    }
    cout<<ans<<endl;
}

int main()
{
    IOS
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return(0);
}

#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD2 1000000006
#define TEMPMOD1 998244353
#define TEMPMOD2 998244352
#define INF 1000000000000000007
#define NEGINF -1000000000000000007
#define vll vector<ll> 
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define vpll vector<pll>
using namespace std;
typedef long long int ll;

ll modexpo(ll base,ll power)
{
    ll result=1;
    while(power!=0)
    {
        if(power&1)
        {
            result=(result*base)%MOD;
        }
        base=(base*base)%MOD;
        power=power>>1;
    }
    return result;
}

ll modinverse(ll num)
{
    ll temp=MOD-2;
    return modexpo(num,temp);
}
// Summing x*(n-x) x=1,...n-1
ll sum1_x_n(ll n)
{
    ll val1=(n*(n+1)*n)/2;
    ll val2=((2*n)+1);
    val2*=(n*(n+1));
    val2=val2/6;
    ll result=val1-val2;
    result=result%MOD;
    return result;
}
// Summing (n-x) fron x=1 to 
ll nonzero(ll n)
{
    ll result=(n*(n-1))/2;
    result=result%MOD;
    return result;
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll factorial[200010];
    factorial[0]=1;
    for(ll i=1;i<200010;i++)
    {
        factorial[i]=(factorial[i-1]*i)%MOD;
    }
    ll result=0,store;
    ll n,m,k;
    cin>>n>>m>>k;
    
    store=(sum1_x_n(m)*(nonzero(n)))%MOD;
    result=(result+store)%MOD;
    store=(sum1_x_n(n)*(nonzero(m)))%MOD;
    result=(result+store)%MOD;
    result=(result*2)%MOD;
    store=(m*sum1_x_n(n))%MOD;
    result=(result+store)%MOD;
    store=(n*sum1_x_n(m))%MOD;
    result=(result+store)%MOD;
    ll cellno=n*m;
    store=factorial[cellno-2];
    store=(store*modinverse(factorial[k-2]))%MOD;
    store=(store*modinverse(factorial[cellno-k]))%MOD;    
    result=(result*store)%MOD;
    cout<<result;
    return 0;
}
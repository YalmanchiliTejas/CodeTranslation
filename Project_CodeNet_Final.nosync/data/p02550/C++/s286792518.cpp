#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
long long const mod = 998244353; 
#define inf 1000000000000000000
inline ll add(ll a, ll b){ return ((a%mod)+(b%mod)+mod)%mod;}
inline ll mul(ll a, ll b){ return (((a%mod)*(b%mod))%mod+mod)%mod;}
inline ll sub(ll a, ll b){ return ((a%mod)-(b%mod)+mod)%mod;}

/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update> */

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

ll power(ll x,ll y,ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
}

ll modInv(ll x)
{
    return power(x,mod-2,mod)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
    ll n;
    cin>>n;
    ll x,m;
    cin>>x>>m;
    vector<ll>v;
    bool a[m];
    memset(a,false,sizeof(a));
    ll prev=x;
    v.push_back(x);
    ll f=-1;
    while(true)
    {
        if(a[prev])
        {
            f=prev;
            break;
        }
        ll z=(prev*prev)%m;
        v.push_back(z);
        a[prev]=true;
        prev=z;
        //cout<<z<<endl;
    }

    ll sum1=0;
    ll num=0;
    for(ll i=0;i<v.size();i++)
    {
        sum1+=v[i];
        num++;
        if(n==num)
        {
            cout<<sum1<<endl;
            return 0;
        }
        if(v[i]==f)
        {
            break;
        }
    }


    ll sz=v.size()-num;
    n=n-num;
    ll q=n/sz;
    ll r=n%sz;
    ll sum2=0;
    for(ll i=num;i<v.size();i++)
        sum2+=v[i];
    ll sum3=0;
    for(ll i=num;i<num+r;i++)
    {
        sum3+=v[i];
    }
    cout<<sum1+sum2*q+sum3<<endl;
    
    return 0;
}



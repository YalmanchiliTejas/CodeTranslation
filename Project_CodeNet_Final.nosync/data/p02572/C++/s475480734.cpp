#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
typedef tree<pair<ll,pair<ll,ll> >, null_type, less<pair<ll,pair<ll,ll> > >, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define me BOSS
#define bug() cout<<"AIkahne aise"<<endl
#define PI acos(-1)
/* Precode Start Here *\
     Sieve
void sieve()
{
    for(ll i=3; i<=2000; i+=2)
    {
        for(ll j=i*i; j<=4000000; j+=i)
            A[j]=1;
    }
    v.push_back(2);
    for(ll i=3; i<=4000000; i+=2)
        if(A[i]==0)
            v.push_back(i);
}

     Power Function Modulo P

ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}


   factorial

ll fact(ll n)
{
    ll ans=1;
    for(ll i=1;i<=n;i++)
    {
        ans=(ans*i)%mod;
    }
    return ans;
}
     Calculating nCr using Fermats law Theorem

ll modInverse(ll a, ll p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}


ll modBinomial(ll n, ll k, ll p) {
// calculates C(n,k) mod p (assuming p is prime).

    ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (ll i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    ll denominator = 1; // k!
    for (ll i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}
     num of divisor and euler totient

ll phi[1000001],mark[1000001],divi[1000001];;
void divisorPhi(ll n)
{
    for(int i=1;i<=n;i++)
        phi[i]=i;
    for(int i=2;i<=n;i++)
    {
        if(!mark[i])
        {
            for(int j=i;j<=n;j+=i)
            {
                mark[j]=1;
                phi[j]*=(1-1/(double)i);
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j+=i)
            divi[j]++;
    }
}
/* Precode Ends */
#define mod 1000000007
ll A[5000001],B[5000001];
vector<ll>v;
map<ll,ll>myMap;
set<ll>mySet;
vector<pair<ll,ll> >vp;
priority_queue<ll> pq;
priority_queue<ll, vector<ll>, std::greater<ll> > first;
ll po(ll a,ll n)
{
    ll ans=1;
    for(int i=1; i<=n; i++)
        ans*=a;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,sum=0,ans=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
        sum+=A[i];
    }
    sum%=mod;
    for(int i=1; i<n; i++)
    {
        sum=(sum-A[i]+mod)%mod;
        ans+=(sum*A[i])%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

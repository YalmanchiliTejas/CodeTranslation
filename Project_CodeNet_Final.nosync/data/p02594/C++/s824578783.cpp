#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vl vector
#define inf LONG_MAX
#define gets getline
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define makestring(x) to_string(x)
#define endl "\n"
#define ss second
#define ff first
#define fast  ios_base::sync_with_stdio(false)
using namespace std;
vl<ll> divisor(ll n)
{
    vl<ll> v;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) 
        {
            if(n/i==i) v.pb(i);
            else
            {
                v.pb(i);
                v.pb(n/i);
            }
        }
    }
    return v;
}

bool isprime(int n)
{
    int i;
    for(i=2;i*i<=n;i++) if(n%i==0) return 0;
    return 1;
}

vl<ll> sieve()
{
    vl<ll> v(1000001);
    int i,j;
    for(i=0;i<1000001;i++) v[i]=1;
    for(i=2;i<=sqrt(1000001);i++) if(v[i]==1) for(j=i*i;j<=1000000;j+=i) v[j]=0;
    v[1]=0;
    return v;
}

string dectobi(ll n)
{
    string s;
    while(n>0)
    {
        if(n&1) s.pb('1');
        else s.pb('0');
        n>>=1;
    }
    reverse(all(s));
    return s;
}

ll power(ll a, ll b, ll m)
{
    ll res=1;
    while(b>0)
    {
        if(b%2) res=(res*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res%m;
}

int main()
{
    fast;
    ll a,b=31,c,d,e,sum=0,flag=0,j=0,i=1,count=0;
    ll x,y,o;
    set<ll> se;
    ll n,m,t,k,l,r;
    string s;
    cin>>n;
    if(n>=30) cout<<"Yes";
    else cout<<"No";
}
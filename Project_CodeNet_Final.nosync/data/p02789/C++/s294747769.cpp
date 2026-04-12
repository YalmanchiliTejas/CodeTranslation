#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);
#define FO cout.tie(NULL);
#define FI cin.tie(NULL);
#define IN cin>>
#define OUT cout<<
#define loop(i,a,n) for(long long int i=a; i<n; i++)
#define rloop(i,a,n) for(long long int i=a; i>=n; i--)
#define endl "\n";
#define pb push_back
#define mp make_pair
#define set_bits(a) __builtin_popcount(a)
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define vll vector<long long int>
#define pll pair<long long int, long long int>
#define stkll stack<ll>
#define qll queue<ll>
#define pqll priority_queue<ll>
#define mod 1000000007
#define M 998244353
ll gcd(ll a, ll b)
{
    return (b?gcd(b,a%b):a);
}
ll P(ll B, ll power, ll modulo)
{
    ll ans=1LL;
    while(power>0LL)
    {
        if(power%2LL==1LL)
        {
            ans=(ans*B)%modulo;
        }
        B=(B*B)%modulo;
        power/=2LL;
    }
    return ans;
}
bool isPrime(ll n)
{
    if(n<=1LL)
    {
        return false;
    }
    if(n<=3LL)
    {
        return true;
    }
    if(n%2==0LL || n%3==0LL)
    {
        return false;
    }
    for(ll i=5LL; (i*i)<=n; i+=6LL)
    {
        if(n%i==0LL || n%(i+2LL)==0LL)
        {
            return false;
        }
    }
    return true;
}
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second<b.second);
}
bool sortbysecll(const pll &a, const pll &b)
{
    return (a.second<b.second);
}
ll modinv(ll x, ll y, ll modulo)
{
    return ((x%modulo)*(P(y,modulo-2LL,modulo)%modulo))%modulo;
}
int main()
{
    FAST
    FO
    FI
    int n,m;
    IN n>>m;
    if(n==m) OUT "Yes";
    else OUT "No";
    return 0;
}

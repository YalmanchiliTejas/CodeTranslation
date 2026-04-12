#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);
#define FO cout.tie(NULL);
#define FI cin.tie(NULL);
#define IN cin>>
#define OUT cout<<
#define loop(i,a,n) for(int i=a; i<n; i++)
#define rloop(i,a,n) for(int i=a; i>=n; i--)
#define endl "\n";
#define pb push_back
#define mp make_pair
#define set_bits(a) __builtin_popcountll(a)
#define ll long long int
#define ld long double
#define vll vector<long long int>
#define pll pair<long long int, long long int>
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
bool sortbysec(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b)
{
    return (a.first.second<b.first.second);
}
bool sortbysecll(const pll &a, const pll &b)
{
    return (a.second<b.second);
}
ll modinv(ll x, ll y, ll modulo)
{
    return ((x%modulo)*(P(y,modulo-2LL,modulo)%modulo))%modulo;
}
void vok()
{
    FAST
    FO
    FI
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
}
int main()
{
    vok();
    ll n;
    IN n;
    vll v(n);
    loop(i,0,n)
    {
        IN v[i];
    }
    ll dp[n][2];
    memset(dp,0,sizeof(dp));
    dp[0][0]=v[0];
    dp[0][1]=0;
    dp[1][0]=max(v[0],v[1]);
    dp[1][1]=(ll)(-1e15);
    loop(i,2,n) 
    {
        if(i%2==0) 
        {
            dp[i][0]=dp[i-2][0]+v[i];
            dp[i][1]=max(dp[i-1][0],dp[i-2][1]+v[i]);
        } 
        else 
        {
            dp[i][0]=max(dp[i-1][0],dp[i-2][0]+v[i]);
            dp[i][1]=(ll)(-1e15);
        }
    }
    // loop(i,0,n)
    // {
    //     OUT dp[i][0]<<" "<<dp[i][1]<<endl
    // }
    OUT dp[n-1][n%2]<<endl
    return 0;
}
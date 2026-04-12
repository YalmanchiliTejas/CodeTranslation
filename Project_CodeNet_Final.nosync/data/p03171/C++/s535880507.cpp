#include <bits/stdc++.h>
#include <math.h>
typedef long long int ll;
#define pb         push_back
#define mp         make_pair
#define F          first
#define S          second
#define fl(i,a,b)  for(ll i=a;i<b;i++)
#define pll        pair<ll,ll>
#define pii        pair<int,int>
#define all(v)     v.begin(),v.end()
#define M          1000000007
#define M2         1000000009
#define M3         1000000000000007

using namespace std;
bool isPrime(ll n)
{
    if(n<=1)
        return false;
    if(n<=3)
        return true;
    if(n%2==0 || n%3==0)
        return false;

    for(ll i=5;i*i<=n;i=i+6)
        if(n%i==0|| n%(i+2)==0)
            return false;

    return true;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b,a%b);

}

bool sortbydesc(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    if(a.S < b.S)
        return true;
    else
        return false;
}

vector<ll> v;
ll dp[3005][3005][2];

ll sol(ll i, ll j, ll turn)
{
    if(dp[i][j][turn]!=M3)
        return dp[i][j][turn];
    if(i==j)
    {
        if(turn==0)
        dp[i][j][turn]=v[i];
        else
            dp[i][j][turn]=-v[i];
        return dp[i][j][turn];
    }
    if(turn == 0)
        dp[i][j][turn]=max(v[i]+sol(i+1,j,1-turn),v[j]+sol(i,j-1,1-turn));
    else
        dp[i][j][turn]=min(sol(i+1,j,1-turn)-v[i],sol(i,j-1,1-turn)-v[j]);
    return dp[i][j][turn];
}

int main()
{
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll n;
 cin>>n;
 
 v.pb(0);
 ll a;
 fl(i,0,n)
 {
    cin>>a;
    v.pb(a);
 }
 fl(i,0,3005)
 {
    fl(j,0,3005)
    {
        dp[i][j][0]=M3;
        dp[i][j][1]=M3;
    }
 }
 ll ans=sol(1,n,0);
 cout<<ans;
}





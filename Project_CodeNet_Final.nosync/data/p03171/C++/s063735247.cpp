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


int main()
{
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll n;
 cin>>n;
 vector<ll> v;
 v.pb(0);
 ll a;
 fl(i,0,n)
 {
    cin>>a;
    v.pb(a);
 }
 ll dp[n+1][n+1][2];
 fl(i,1,n+1)
 {
    dp[i][i][0]=v[i];
    dp[i][i][1]=-v[i];
 }
 for(ll i=n-1;i>0;i--)
 {
    for(ll j=i+1;j<=n;j++)
    {
        dp[i][j][0]=max(v[i]+dp[i+1][j][1],v[j]+dp[i][j-1][1]);
        dp[i][j][1]=min(dp[i+1][j][0]-v[i],dp[i][j-1][0]-v[j]);
    }
 }
 cout << dp[1][n][0];
}





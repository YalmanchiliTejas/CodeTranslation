#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using llu=unsigned long long;
#define mod 1000000007
#define mode 998244353
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mms(x,y) memset(x,y,sizeof(x))
#define pqm priority_queue<ll,vector<ll>,greater<ll>>
#define pb push_back
#define um unordered_map
#define pr pair
#define mm multimap
#define ms multiset
#define mp make_pair
#define vr vector
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define inf INT_MAX
#define ninf INT_MIN
#define ff first
#define ss second
#define gcd __gcd
ll d;
ll dp[10001][2][100];
ll rohan(ll p,ll c,ll s,string &g)
{
    if(p==g.size())return (s%d==0);
    if(dp[p][c][s]!=-1)return dp[p][c][s];
    ll k=9;
    if(c==0)k=g[p]-'0';
    ll ans=0;
    for(ll i=0;i<=k;i++)
    {
        ll m=1;
        if(i==k)m=c;
        ans=(ans+rohan(p+1,m,(s+i)%d,g))%mod;
    }
    return dp[p][c][s]=ans;
}
int main()
{
    fast;
    ll t,n,m,i,j,k;
    string s;
    cin>>s;
    cin>>d;
    mms(dp,-1);
    ll ans=rohan(0,0,0,s);
    ans=(ans-1+mod)%mod;
    cout<<ans;
}

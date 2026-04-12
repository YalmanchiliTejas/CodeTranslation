#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll> ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <vector <vector<ll> > > vvv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define tr1(x) cerr << #x << ": " << x << endl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define tr4(x,y,z,w) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#w<<": "<<w<<endl
#define trv(a) cerr<<#a<<": ";for(ll zz=0;zz<a.size();zz++) cerr<<a[zz]<<" ";cerr<<endl
#define trset(s) cerr<<#s<<": ";for(auto &i:s) cerr<<i<<" ";cerr<<"\n"
#define mod 1000000007ll
#define inf 9999999999999999ll
#define nl endl
#define modulo 998244353
ll fun(vi &a,ll index,ll sum,bool selected,vector <vv> &dp)
{
    ll n=a.size();
    if(sum<0)
        return 0;
    if(sum==0)
        return index+2;
    if(index==0)
    {
        if(a[0]==sum)
            return 1;
        return 0;
    }
    if(selected)
    {
        if(dp[index][sum][1]!=-1)
            return dp[index][sum][1];
        dp[index][sum][1]=fun(a,index-1,sum,true,dp)+fun(a,index-1,sum-a[index],true,dp);
        dp[index][sum][1]%=modulo;
        return dp[index][sum][1];
    }
    else
    {
        if(dp[index][sum][0]!=-1)
            return dp[index][sum][0];
        dp[index][sum][0]=fun(a,index-1,sum,false,dp)+(fun(a,index-1,sum-a[index],true,dp)*(n-index))%modulo;
        dp[index][sum][0]%=modulo;
        return dp[index][sum][0];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s;
    cin>>n>>s;
    vi a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll ans=0;
    vector <vv> dp(n,vv (3001,vi(2,-1)));
    ans=fun(a,n-1,s,false,dp);
    cout<<ans<<"\n";
}

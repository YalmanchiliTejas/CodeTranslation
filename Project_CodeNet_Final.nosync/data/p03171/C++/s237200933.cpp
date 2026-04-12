/// Code By t_bone_289 (Tushar Singh)
/// An Immature Programmer.... I'm still developing !!
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define endl '\n'
#define M 1000000007
#define error(x) cout << #x << " = " << x << endl;
#define pi 3.14159265358979323846
typedef long long ll;
typedef double d;
typedef long double ld;
template <typename T>
void ContainerError(T &v){cout<<"{";for(auto &x:v){cout<<x<<',';}cout<<"}"<<endl;return;}
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
ll mpow(ll base,ll exp){ll res=1;while(exp>0){if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return (res);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

ll sol(ll i,ll j,vector<ll> &v,vector<vector<ll> > &dp)
{
    if(i==j)
    {
        return dp[i][j]=v[i];
    }
    if(i+1==j)
    {
        return dp[i][j]=max(v[i]-v[j],v[j]-v[i]);
    }
    if(i>j)
    {
        return INT_MAX;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll ans1 = v[i] + min(sol(i+2,j,v,dp)-v[i+1],sol(i+1,j-1,v,dp)-v[j]);
    ll ans2 = v[j] + min(sol(i+1,j-1,v,dp)-v[i],sol(i,j-2,v,dp)-v[j-1]);
    return dp[i][j]=max(ans1,ans2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &x:v)
    {
        cin>>x;
    }
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,-1));
    ll ans = sol(0,n-1,v,dp);
    cout<<ans;
    return 0;
}


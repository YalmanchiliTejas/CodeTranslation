//author:satwik_bhv1
#include<bits/stdc++.h>
//datatypes
#define ll long long 
#define ld long double
//loops
#define fr(i,z,n) for(ll i=z;i<n;i++)
#define br(i,z,n) for(ll i=z;i>n;i--)
//operations
#define mp  make_pair
#define ff  first
#define ss  second
#define pub push_back
#define all(v) v.begin(),v.end()
//map
#define mi map<ll,ll>
//vectors
#define vi vector<ll>
#define vpi vector<pair<ll,ll> >
//constants
#define pi 3.1415926535897932384626
#define mod 1000000007 
#define MAXN 100001
/*notes
    Don't use inbuilt fun for power
    Range of longlong=(-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 )
    INT_MAX = 2147483647(aprox 2*10^10)
    INT_MIN = -2147483648
    LLONG_MAX = 9223372036854775807 
    LLONG_MIN = -9223372036854775808
    __gcd is the function in built for hcf
    priority queue is max heap by default
    topological sort -> khan's algo use bfs and indegree of node  
    sssp(positive weighted edges) -> Dijkstras
    apsp -> Floydwarshall
    MST -> kruskal(DSU)
*/
using namespace std;
//functions
ll power(ll x,ll y){ll res=1;while(y){if(y%2){res*=x;}y/=2;x*=x;} return res;}
ll power(ll x,ll y,ll z){ll res=1;while(y){if(y%2){res=(res*x)%z;}y/=2;x=(x*x)%z;} return res;}
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
bool sortbysec(const pair<ll, ll>& a, const pair<ll, ll>& b) { return (a.second > b.second); }
ll ceil(ll x,ll y){return (x/y)+(x%y!=0);}
ll n;
ll v[3000];
ll dp[3000][3000][2];
ll res;
ll fun(ll l,ll r,ll turn)
{
    ll ans;
    if(l==r)
    {
        if(turn==0)
        {
            ans=v[l];
        }
        else
        {
            ans=-1*v[l];
        }
    }
    else
    {
        ll left,right;
        if(dp[l+1][r][1-turn]!=-1)
        {
            left=dp[l+1][r][1-turn];
            if(turn==0)
            {
                left+=v[l];
            }
            else
            {
                left-=v[l];
            }
        }
        else
        {
            left=fun(l+1,r,1-turn);
            if(turn==0)
            {
                left+=v[l];
            }
            else
            {
                left-=v[l];
            }
        }
        if(dp[l][r-1][1-turn]!=-1)
        {
            right=dp[l][r-1][1-turn];
            if(turn==0)
            {
                right+=v[r];
            }
            else
            {
                right-=v[r];
            }
        }
        else
        {
            right=fun(l,r-1,1-turn);
            if(turn==0)
            {
                right+=v[r];
            }
            else
            {
                right-=v[r];
            }
        }
        if(turn==0)
        {
            ans=max(left,right);
        }
        else
        {
            ans=min(left,right);
        }
    }
    dp[l][r][1-turn]=-1*ans;
    return dp[l][r][turn]=ans;
}
void solve()
{
    cin>>n;
    fr(i,0,n)
    {
        cin>>v[i];
    }
    fr(i,0,n)
    {
        fr(j,0,n)
        {
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    cout<<fun(0,n-1,0);
    //cout<<res<<"\n";
}
int main()
{
    fast();
    ll t;
    t=1;
    //cin>>t;
    fr(i,0,t)
    {
        solve();
    }
}
/*





























*/
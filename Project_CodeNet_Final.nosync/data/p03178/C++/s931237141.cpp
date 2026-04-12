#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  10005

ll dp[N][100][2];
ll n,d;
vi v;
ll tim=0;
ll dps(ll ind,ll mod,ll flg)
{
    if(ind==n)
    {
        if(mod==0)
        return 1;
        return 0;
    }
    if(dp[ind][mod][flg]!=-1)
        return dp[ind][mod][flg];
    ll x=0;
    if(flg==1)
    rep(i,0,10)
    {
        if(i<v[ind])
        {
            x=(x+dps(ind+1,(mod+i)%d,0))%hell;
        }
        else if(i==v[ind])
        {
            x=(x+dps(ind+1,(mod+i)%d,1))%hell;       
        }
    }
    else
    rep(i,0,10)
    {
        x=(x+dps(ind+1,(mod+i)%d,0))%hell;  
    }   
    return dp[ind][mod][flg]=x;
}
void solve()
{
    string s;
    cin>>s;
    n=sz(s);
    cin>>d;
    for(auto u:s)
        v.pb(u-'0');
    // cout<<n<<endl;
    memset(dp,-1,sizeof(dp));
    cout<<(dps(0,0,1)-1+hell)%hell<<endl;
    // rep(i,0,n+1)
    // {
    //     rep(j,0,d)
    //     {
    //         cout<<dp[i][j][0]<<" ";
    //     }
    //     cout<<endl;
    // }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}
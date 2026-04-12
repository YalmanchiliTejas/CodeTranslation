#pragma optimize("unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define pc(x)  __builtin_popcount (x)
#define vl vector< ll >
#define sorts(v) sort(v.begin(),v.end())
#define sortg(v) sort(v.begin(),v.end(),greater<ll>())
#define ss second
#define ff first
#define ll long long
#define ld long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1e18)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define gcd __gcd
#define primeDEN 727999983
#define nx_pe next_permutation(s.begin(),s.end())
#define cl cout<<"\n"
#define sp(x) setprecision(x)
const ll N=3005;
ll dp[N][N][2];
ll a[N];
ll n;

ll fun(ll i,ll j,ll turn)
{
    if(i==j)
    {
        return a[i];
    }
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j][turn]!=-1)return dp[i][j][turn];
    ll ans=-1e18;
    if(turn==1)
    {
        ans=max(ans,max(a[i]-fun(i+1,j,turn^1),a[j]-fun(i,j-1,turn^1)));
    }
    else
    {
        ans=max(ans,max(a[i]-fun(i+1,j,turn^1),a[j]-fun(i,j-1,turn^1)));
    }
    return dp[i][j][turn]=ans;
    
}

void solve()
{
   cin>>n;
   rep(i,n)cin>>a[i];
   mem(dp,-1);
   ll x=fun(0,n-1,0);
   cout<<x<<"\n";

   
}


    
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("ouput.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    std::ios::sync_with_stdio(false);
    ll te=1;
    // cin>>te;
    while(te--){
        solve();
    }
    
}

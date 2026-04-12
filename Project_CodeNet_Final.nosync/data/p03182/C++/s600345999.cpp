

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define int long long int
typedef complex<long double> cd;
const long double pi=acos(-1);
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <db, db> pdd;
typedef vector<int> vi;


#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))

#define fi first
#define se second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}

const ll MOD =998244353;
const ll hell=1000000007;
const int INF=1e15;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

const int N=200005;
int st[4*N],lazy[4*N];
int dp[N][2];
void update(int i,int l,int r,int qs,int qe,int x)
{
   if(lazy[i])
   {
       st[i]+=lazy[i];
       if(l!=r)
       {
           lazy[2*i+1]+=lazy[i];
           lazy[2*i+2]+=lazy[i];
       }
       lazy[i]=0;
   }
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        st[i]+=x;
        if(l!=r)
        {
            lazy[2*i+1]+=x;
            lazy[2*i+2]+=x;
        }
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,qs,qe,x);
    update(2*i+2,m+1,r,qs,qe,x);
    st[i]=max(st[2*i+1],st[2*i+2]);
}
int query(int i,int l,int r,int qs,int qe)
{
    if(lazy[i])
    {
        st[i]+=lazy[i];
        if(l!=r)
        {
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(qs>r||qe<l)
        return -INF;
    if(qs<=l&&qe>=r)
        return st[i];
    int m=(l+r)/2;
    return max(query(2*i+1,l,m,qs,qe),query(2*i+2,m+1,r,qs,qe));
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<4*n;i++)
        st[i]= -INF;
    dp[0][0]=0;
    dp[0][1]=0;
    //debug(1);
    update(0,0,n,0,0,INF);
    vector<pair<int,int>> ve[n+1];
    int l,r,a;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r>>a;
        ve[r].pb(m1(l,a));
    }
    int s;
    for(int i=1;i<=n;i++)
    {
         s=0;
        for(int j=0;j<ve[i].size();j++)
        {
            s=s+ve[i][j].se;
        }
        dp[i][1]=max(dp[i-1][0],dp[i-1][1])+s;
        for(int j=0;j<ve[i].size();j++)
        {
             if(ve[i][j].fi!=i)
            update(0,0,n,ve[i][j].fi,i-1,ve[i][j].se);
        }
        dp[i][0]=query(0,0,n,0,i-1);
        update(0,0,n,i,i,INF+dp[i][1]);
        
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
        
    
}

int32_t main()
{
    
    IOS;
   
    //FILE *fin = freopen("in","r",stdin);
    //FILE *fout = freopen("out","w",stdout);
    int t;
    t=1;
   // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}


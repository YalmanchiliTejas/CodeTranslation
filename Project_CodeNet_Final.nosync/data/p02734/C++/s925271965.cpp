
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
typedef vector<vector<int> > matrix;

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
const ll hell=MOD;
const int INF=3e17;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);
const int N=3001;
int s;int a[N];
int dpl[3001],dpr[3001];int suff[3001],pre[3001];int n;
int solve(int l,int r)
{
    if(l==r)
    {
        if(a[l]==s)
            return ((l+1)*(n-r))%hell;
        else
            return 0;
    }
    int m=(l+r)/2;
    int ansl=solve(l,m);
    int ansr=solve(m+1,r);
    int ans=(ansl+ansr)%hell;
    memset(dpl,0,sizeof(dpl));
    memset(dpr,0,sizeof(dpr));
    memset(suff,0,sizeof(suff));
    memset(pre,0,sizeof(pre));
    dpl[0]=0;suff[0]=1;
    dpr[0]=0;pre[0]=1;
    for(int i=m;i>=l;i--)
    {
        for(int j=s;j>=0;j--)
        {
            if(a[i]<=j)
            {
                dpl[j]=(dpl[j]+((i+1)*suff[j-a[i]])%hell)%hell;
                suff[j]=(suff[j]+suff[j-a[i]])%hell;
            }
        }
    }
    for(int i=m+1;i<=r;i++)
    {
        for(int j=s;j>=0;j--)
        {
            if(a[i]<=j)
            {
                dpr[j]=(dpr[j]+(n-i)*pre[j-a[i]])%hell;
                pre[j]=(pre[j]+pre[j-a[i]])%hell;
            }
        }
    }
    for(int i=1;i<s;i++)
        ans=(ans+(dpl[i]*dpr[s-i])%hell)%hell;
    
    return ans;
    
}
void solve()
{
    //int n;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(0,n-1)<<endl;
}
int32_t main()
{
    
    IOS;
    //FILE *fin = freopen("in","r",stdin);
    //FILE *fout = freopen("out","w",stdout);
    int t;
    t=1;
    //cin>>t;
    
    while(t--)
    {
        
        
        solve();
    }
    return 0;
}



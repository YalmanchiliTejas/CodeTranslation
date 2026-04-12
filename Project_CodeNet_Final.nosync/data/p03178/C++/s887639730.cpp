

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

const int N=3005;

int dp[10005][101];
int d;

int cal(string s)
{
    int ans=0;
    int n=s.length();
    int cr=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(s[i]-'0');j++)
        {
            int z=(cr+j)%d;
            ans=(ans%hell+dp[n-i-1][(d-z)%d]%hell)%hell;
            
        }
        cr=(cr+(s[i]-'0'))%d;
    }
    if(!(cr%d))
        ans=(ans+1)%hell;
   // if(ans>0)
    ans=(ans-1+hell)%hell;
    return ans;
}
void solve()
{

    string s;
    cin>>s;
    cin>>d;
    int n=s.length();
    dp[0][0]=1;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=0;j<d;j++)
        {
            for(int k=0;k<10;k++)
            {
                dp[i][j]=(dp[i][j]%hell+dp[i-1][(j-k%d+d)%d]%hell)%hell;
            }
        }
    }
    //debug(1);
    cout<<cal(s)<<endl;
    
    
        

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


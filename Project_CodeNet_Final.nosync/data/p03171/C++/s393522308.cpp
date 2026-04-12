//At coder k stones 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long int
#define ld long double
#define f(t) for(ll i =0;i<t;i++)
#define vi vector<int>
#define vl vector<ll>
#define pri pair<int,int>
#define mpi map<int,int>
#define prl pair<ll,ll>
#define mp make_pair
#define mpl map<ll,ll>
#define umpl unordered_map<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define inf 2e18
#define EPS 1e-3
#define PI 3.1415926535897932385
const double h = 1e-6;
const int MAX_  = 100005;
#define display(v) f(v.size())cout << v[i] << " "
#define all(v) v.begin(),v.end()

inline ll mul(ll a, ll b){ return (a * 1ll * b) % MOD; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }
 //////////////////////*********CODE***********/////////////////////
 //////////////////////////////////////////////////////////////////
ll dp[3001][3001];
ll get_ac(ll arr[],int i,int j)
{
    if(i==j)
    {
        return arr[i];
    }
   else if(i+1==j)
    {
        return max(arr[i],arr[j]);
    }
    else if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        dp[i][j] = max(arr[i]+min(get_ac(arr,i+2,j),get_ac(arr,i+1,j-1)), arr[j] + min(get_ac(arr,i+1,j-1),get_ac(arr,i,j-2)));
        return dp[i][j];
    }
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    ll sum = 0;
    memset(dp,-1,sizeof(dp));
    ll arr[n]; f(n){cin>>arr[i];sum+=arr[i];}
   // sum = accumulate(arr,arr+n,0);
    ll x = get_ac(arr,0,n-1);
 //   cout << sum << " " << x << "\n";
    ll y = sum - x;
    cout << x-y << "\n";
    
    
    return 0;
 }
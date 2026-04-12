#include <bits/stdc++.h>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
*/

using namespace std;

#if DEBUG && !ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<int> > vvi;
typedef vector<vector<ii> > vvii;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define ff first
#define ss second
#define trav(a, x) for(auto& a : x) 
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
const ll INF = 1e18;
const int mod =  1e9 + 7;
const int N = 1e5;
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

//*X.find_by_order(2) element at index=2
//X.order_of_key(1) how many elements strictly less than 1

/*
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
*/

inline int pow_(ll x, ll y,ll p){
  int r = 1; while(y){if(y & 1) r = r * x % p; y >>= 1; x = x * x % p;} return r;
}
inline int inv_(int x){return pow_(x, mod - 2, mod);}
inline int add(int a, int b){a += b; if(a >= mod) a -= mod; return a;}
inline int mul(int a, int b){return a * 1LL * b % mod;}
inline int sub(int a, int b){a -= b; if(a < 0) a += mod; return a;}



int main()
{
	#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
    //freopen("out.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #endif
   	ll n;
   	cin>>n;
   	ll f = 1;
   	if(n%2)f = 0;
   	ll a[3005] = {0};
   	ll sum[3005] = {0};
   	for(int i=1;i<=n;i++)
   	{
   		cin>>a[i];
   		sum[i] = a[i] + sum[i-1];
   	}

   	ll dp[3005][3005] = {0};
   	for(int i=1;i<=n;i++)
   	{
   		dp[i][i] = a[i];
   	}

   	for(int l=1;l<=n;l++)
   	{
   		for(int i=1;i<=n-l;i++)
   		{
   			int j = i+l;
   			dp[i][j] = max(a[i] + ((sum[j]-sum[i])-dp[i+1][j]) , a[j] + ((sum[j-1]-sum[i-1])-dp[i][j-1]));
   		}
   	}

   	cout << 2*dp[1][n]-sum[n] << "\n";

	return 0;
}
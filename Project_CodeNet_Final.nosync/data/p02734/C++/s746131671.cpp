#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 1000000000
#define ninf -1000000000
#define endl '\n' 
#define she_told_me_dont_worry ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// Use cout.flush() for interactive problems.
// Use this for increased stack size: g++ -o a.exe -Wl,--stack=256000000 -O2 source.cpp
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< ii > vii;
const ll N = 3e3+5;
const ll MOD = 998244353;
ll n, s;
ll dp[N][N][4];
ll a[N];
ll compute(ll i, ll left, ll start)
{
    if(left < 0 ) return 0;
    if( left == 0) return dp[i][left][start] = (n-i+1)%MOD;
    if( i == n) return 0;
    if(dp[i][left][start] != -1) return dp[i][left][start];
    ll ans = 0;
    // take
    if(!start)
    {
        ll val = compute(i+1, left-a[i], 1);
        val *= i+1;
        val %= MOD;
        ans += val;
        ans %= MOD;
    }
    else 
    {
        ll val = compute(i+1, left-a[i], 1);
        ans += val;
        ans %= MOD;
    }

    // do not take
    ll val = compute(i+1, left, start);
    ans += val;
    ans %= MOD;
    
    return dp[i][left][start] = ans;

}
int main()
{
    she_told_me_dont_worry
    cin>>n>>s;
    ll i, j, k;
    FOR0(i, n) cin>>a[i];
    FOR0(i, n+2)FOR0(j, s+2)FOR0(k, 3) dp[i][j][k] = -1;
    cout<<compute(0, s, 0)<<endl;
    cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
}
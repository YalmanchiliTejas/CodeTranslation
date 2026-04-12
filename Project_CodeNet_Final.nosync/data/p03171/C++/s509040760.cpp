#include<bits/stdc++.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 1e17
#define ninf -1e17
#define endl '\n' 
#define she_told_me_dont_worry ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
// Use cout.flush() for interactive problems.
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< ii > vii;
ll n;
ll dp[3005][3005][3];
ll a[3005];
ll compute(ll s, ll e, ll turn)
{
    if(s>e)
    {
        return 0;
    }
    if(dp[s][e][turn]!=ninf) return dp[s][e][turn];
    ll ans;
    if(turn == 0)
    {
        ans = ninf;
        ans = MAX2(ans, a[s] + compute(s+1, e, 1-turn));
        ans = MAX2(ans, a[e] + compute(s, e-1, 1-turn));
    }
    else 
    {
        ans = inf;
        ans = MIN2(ans, -a[s] + compute(s+1, e, 1-turn));
        ans = MIN2(ans, -a[e] + compute(s, e-1, 1-turn));
    }
    return dp[s][e][turn] = ans;
}
int main()
{
    she_told_me_dont_worry
    cin>>n;
    int i;
    FOR0(i, n) cin>>a[i];
    int j, k;
    FOR0(i, n+1)FOR0(j, n+1)FOR0(k, 3) dp[i][j][k] = ninf;
    cout<<compute(0, n-1, 0);
    cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
}
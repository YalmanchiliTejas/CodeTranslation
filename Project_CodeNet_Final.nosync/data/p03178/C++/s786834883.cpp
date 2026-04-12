#include<bits/stdc++.h>
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
#define MOD 1000000007
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
ll d;
ll n;
string s;
ll dp[10005][105][2];
ll compute(ll i, ll cur, ll m)
{
    if(i==n)
    {
        if(cur==0) return 1;
        return 0;
    }
    if(dp[i][cur][m]!=-1) return dp[i][cur][m];
    ll ans = 0;
    ll j;
    ll b = s[i] - '0';
    if(m==0)
    {
        FOR0(j, 10)
        {
            ans += compute(i+1, (cur+j)%d, 0);
            ans %= MOD;
        }
    }
    else 
    {
        FOR0(j, b)
        {
            ans += compute(i+1, (cur+j)%d, 0);
            ans %= MOD;
        }
        ans += compute(i+1, (cur+b)%d, 1);
        ans %= MOD;
    }
    return dp[i][cur][m] = ans;
}
int main()
{
    she_told_me_dont_worry
    cin>>s;
    cin>>d;
    n = s.size();
    int i;
    ll sum = 0;
    FOR0(i, n)
    {
        sum += s[i] - '0';
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    ll b = s[0] - '0';
    FOR0(i, b)
    {
        ans += compute(1, (i)%d, 0);
        ans %= MOD;
    }
    ans += compute(1, b%d, 1)-1;
    ans %= MOD;
    cout<<ans;
    cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
}
//AUTHOR - NAVEEN KUMAR(@naveen19991124)
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#inlcude<boost/multiprecision/cpp_dec_float.hpp>
#define ll long long
#define pb push_back
#define f(a) for(ll i = 0;i<a;i++)
#define rep(i,a,b) for(ll i = a;i<b;i++)
#define rrep(i,a,b) for(ll i = a;i>b;i--)
#define v vector<ll>
#define mp make_pair
#define fir first
#define sec second
#define _fast_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
//using boost :: multiprecision :: cpp_int;
//using boost :: multiprecision :: cpp_dec_float_50;
//using boost :: multiprecision :: cpp_dec_float_100;
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}

ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1;
a *= a; a %= mod;} return p % mod;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll n,sum1,sum2;
ll arr[3005];
ll dp[3000][3000];
ll go_dp(ll x,ll y)
{
    if(x>y || x>n-1 || y<0)
    {
        return 0;
    }
    if(dp[x][y] != -1)
    {
        return dp[x][y];
    }
    if(x == y)
    {
        return dp[x][y] = arr[x];
    }
    dp[x][y] = max(arr[x]-go_dp(x+1,y),arr[y]-go_dp(x,y-1));
    return dp[x][y];

}
int main()
{
    _fast_
    ll t = 1;
    //cin>>t;
    while(t--){
    cin>>n;
    sum1 = 0;
    sum2 = 0;

    f(n)
    {
        cin>>arr[i];
        sum2 += arr[i];
    }
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            dp[i][j] = -1;
        }
    }
    sum1 = go_dp(0,n-1);
    cout<<sum1<<"\n";
    }
    return 0;
}
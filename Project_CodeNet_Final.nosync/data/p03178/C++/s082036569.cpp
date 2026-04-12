#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define M2 998244353
#define ll long long
#define pll pair<long,long>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define ff first
#define ss second
#define pb push_back
#define db pop_back
#define mp make_pair
#define mt make_tuple
#define g(a,b) get<a>(b)
#define INF (ll)1e18+100
 
#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
 
/*ll modI(ll a, ll m);
ll gcd(ll a, ll b);
ll powM(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
ll logint(ll x,ll y);
 
 
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
 
ll modI(ll a, ll m)
{
   return powM(a, m-2, m);
}
 
void pairsort(int a[],int b[],int n)
{
    pair<int,int> v[n];
    REP(i,0,n)
    {
        v[i].ff=a[i];
        v[i].ss=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].ff;
        b[i]=v[i].ss;
    }
}
 
void pairsortll(ll a[],ll b[],ll n)
{
    pair<ll,ll> v[n];
    REP(i,0,n)
    {
        v[i].ff=a[i];
        v[i].ss=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].ff;
        b[i]=v[i].ss;
    }
}
 
ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<=x;i++)
    {
        if(x<a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}*/
const int N = 1e4+5;
ll dp[101][N][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //Hey, You
    // Don't practise these
    // easy questions.
    string s;
    int d;
    cin>>s>>d;
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    REP(i,0,10){
        if(i < s[0]-'0'){
            dp[i][0][0] = 1;
            //dp[i][0][0] %= M;
        }
        else if(i == s[0]-'0'){
            dp[i%d][0][1] = 1;
            //dp[i][0][1] %= M;
        }
        else{break;}
    }
    REP(i, 0, n-1){
        int z = s[i+1]-'0';
        REP(j, 0, min(101,d+10)){
            REP(k, 0, 2){
                if(k == 0){
                    REP(h, 0, 10){
                        dp[(j+h)%d][i+1][0] += dp[j][i][0];
                        dp[(j+h)%d][i+1][0] %= M;
                    }
                }
                else{
                    REP(h,0,z){
                        dp[(j+h)%d][i+1][0] += dp[j][i][k];
                        dp[(j+h)%d][i+1][0] %= M;
                    }
                    dp[(j+z)%d][i+1][1] += dp[j][i][k];
                    dp[(j+z)%d][i+1][1] %= M;
                }
            }
        }
    }
    ll ans=0;
    ans = (dp[0][n-1][0]+dp[0][n-1][1]-1+M)%M;
    cout<<ans%M;
}
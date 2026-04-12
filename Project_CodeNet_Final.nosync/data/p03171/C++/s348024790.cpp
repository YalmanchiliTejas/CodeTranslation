/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( )
* special cases (n=1?)
* 1LL<<i and not 1<<i
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/

// Author:: Subash Singha Roy
// Institution:: Jalpaiguri Government Engineering College

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(998244353)
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a-1;i>=b;i--)
#define tc(t) int t;cin >>t;while(t--)
#define pb emplace_back
#define ee emplace
#define rr return 0
#define mp make_pair
#define pr  pair <ll,ll>
#define ff first
#define ss second
#define pie 3.1415926535
#define inf 999999999999999999
ll mult(ll a,ll b, ll p=mod){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=mod){return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = mod) {return fpow(a, p - 2, p);}
bool sa(const pair<ll,ll> &a,const pair<ll,ll> &b){return (a.second<b.second);}
bool fd(const pair<ll,ll> &a,const pair<ll,ll> &b){return (a.first>b.first);}
bool sd(const pair<ll,ll> &a,const pair<ll,ll> &b){return (a.second>b.second);}
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
bool valid(ll x,ll y,ll n,ll m){
    if(x<0 || y<0){
       return false;
   }
   else if(x>=n || y>=m){
       return false;
   }
   else
   return true;
}

ll dp[3005][3005];
int main(){
    fio;
    ll n;
    cin>>n;
    ll a[n+5];
    fr(i,0,n){
        cin>>a[i];
    }
    for(ll l=n-1;l>=0;l--){
        for(ll r=l;r<n;r++){
            if(l==r){
                dp[l][r]=a[l];
            }
            else{
                dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
    rr;
}
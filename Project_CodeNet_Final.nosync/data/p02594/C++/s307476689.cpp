/* nuttela - Soham Chakrabarti */

#include <bits/stdc++.h>
 
using namespace std;
 
#define io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(v) v.begin(),v.end()
#define pb push_back
#define ins insert
#define rep(i,j,k) for(ll i=j;i<k;i++)
#define per(i,j,k) for(ll i=j;i>=k;--i)
#define scan(a,n) rep(i,0,n)cin>>a[i]
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
#define error freopen("error.txt","w",stderr)
#define ff first
#define ss second
 
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int N = 1e6+1;
const int MAX = 1e6+1; 
const int inf = INT_MAX;
const int mod = 1e9+7;

ll powm(ll a,ll b) {ll res=1LL;while(b) {if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
ll modmult(ll a,ll b) {ll r=0;a%=mod;while(b){if(b&1)r=(r+a)%mod;a=(a<<1)%mod;b>>=1;}return r;}
ll modexpo(ll a,ll b) {ll r=1;a%=mod;while(b){if(b&1)r=(r*a)%mod;a=(a*a)%mod;b>>=1;}return r;}

ll a[N],b[N];

int32_t main() {
    io;
    ll n;cin>>n;
    if(n>=30)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}

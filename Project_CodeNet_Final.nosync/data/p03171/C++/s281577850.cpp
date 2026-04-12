#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  5005;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll n,vis[N][N],a[N];
 
ll rem(int f,int i,int j){
    if(vis[i][j] != 0) return vis[i][j];
    if(i > j) return 0;
    if(f == 0)
        vis[i][j] = min(rem(1,i+1,j),rem(1,i,j-1));
    else
        vis[i][j] = max(a[i]+rem(0,i+1,j),a[j]+rem(0,i,j-1));
    return vis[i][j];
}
 
int main(){
    fastio;
    cin>>n;
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
      	s += a[i];
    }
    ll x = rem(1,0,n-1);
    cout<<2*x-s<<endl;
}
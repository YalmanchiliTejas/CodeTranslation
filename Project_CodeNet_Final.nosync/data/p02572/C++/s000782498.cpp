#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];}
#define NofSetBits(x) __builtin_popcount(x);
#define InpGrph(g,e) while(e--){ll x;ll y;cin>>x>>y ;g[x].pub(y);g[y].pub(x);}
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);




int main(){
  FastIO;
  ll n;
  cin>>n;
  ll a[n];
  ll prfx[n+1];
  for(ll &x : prfx){
    x =0;
  }
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  prfx[0] = a[0];
  for(ll i=1;i<n;i++){
    prfx[i] = a[i]+prfx[i-1];
  }
  ull sum =0;
  for(ll i=0;i<n-1;i++){
    sum = (sum%mod + ((a[i]%mod*((prfx[n-1] - prfx[i])%mod))))%mod;
  }
  cout<<sum;


  return 0;
} 



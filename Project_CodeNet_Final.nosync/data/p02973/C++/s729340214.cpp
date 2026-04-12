#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll n;cin>>n;
  vll b(0),a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  reverse(a.begin(),a.end());
  b.push_back(a[0]);
  rep(i,1,n){
    int dist = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
    if(dist >= b.size()){
      b.push_back(a[i]);
    }
    else{
      b[dist] = a[i];
    }
  }
  cout<<b.size()<<endl;
}



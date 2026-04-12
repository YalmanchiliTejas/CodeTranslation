#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<string> vs;
typedef vector<bool> vb;

const ll mod=1e9+7;
const ll inf=1e16;

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m-1;i>=n;i--)
#define fi first
#define se second
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define eb(x) emplace_back(x)
#define all(x) x.begin(),x.end()
#define gll greater<ll>()


ll n;
vll a;
 
void solve(){
 cin >> n;
 a.resize(n);
 rep(i,0,n) cin >> a[i];
 vll d;
 rep(i,0,n){ 
  auto it=lower_bound(d.rbegin(),d.rend(),a[i]);
  if(it==d.rbegin()){
    d.eb(a[i]);
  }else{
   --it;
   *it=a[i]; 
    
  }
   
 }
  cout << d.size() << endl;
}

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}  
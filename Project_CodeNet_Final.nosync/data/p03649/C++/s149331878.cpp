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

void solve(){
 ll n;
  cin >> n;
 vll a(n);
  rep(i,0,n) cin >> a[i];
 
  
  ll f=1; 
 ll ans=0; 
 while(f){ 
  ll s=0;
  vll num(n);
  rep(i,0,n){
   num[i]=a[i]/n; 
   s+=num[i];
  }
  rep(i,0,n){
   a[i]-=num[i]*n; 
   a[i]+=s-num[i];
  } 
  ans+=s; 
  
  if(*max_element(all(a))<n) f=0;
  
 }
  cout << ans << endl; 
}

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}  
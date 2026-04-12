#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> P;
typedef string str;
typedef vector<P> vp;
typedef vector<string> vs;
typedef vector<bool> vb;

const ll mod=998244353;
const ll inf=1e18;

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m-1;i>=n;i--)
#define fi first
#define se second
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define eb(x) emplace_back(x)
#define pb(x) pop_back(x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sum(x) accumulate(all(x),0)
#define lb(x,a) lower_bound(all(x),a)
#define ub(x,a) upper_bound(all(x),a)
#define pc(x) __builtin_popcount(x)
#define gll greater<ll>()

void solve(){
 ll n,x,m;
  cin >> n >> x >>m;
 ll s=0; 
 map<ll,ll> mp;
  vll v;
  ll z=n;
  while(z--){
    if(mp[x]>=2) break;
    mp[x]++;
    s+=x;
    x*=x;
    x%=m;
    if(x==0||z==0) {
      cout << s << endl;
      return; 
    }
  }
 
  ll num=0;
  ll ans=0;
  s=0;
  for(auto p:mp){
   if(p.se==2){
    s+=p.fi;
    num++; 
   }else{
    ans+=p.fi;
    n--; 
   }
  }
  
  ans+=(n/num)*s;
  n-=(n/num)*num;
  
  while(n--){
   ans+=x;
   x*=x;
   x%=m; 
  }
  cout << ans << endl;
  
}
int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);
  solve();
}
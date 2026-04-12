#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vst;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;


const ll mod=1e9+7;
const ll inf=1e16; 

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m;i>=n;i--)


int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);

 ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  
  ll res=inf;
  
  rep(ab,0,max(x,y)+1){
   res=min(res,ab*2*c+max(0ll,(x-ab))*a+max(0ll,(y-ab))*b);
  }
  cout << res << endl;
  
}

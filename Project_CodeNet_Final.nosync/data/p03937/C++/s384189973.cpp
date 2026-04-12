#include <bits/stdc++.h>
 
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
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;

int main(){
  ll h,w;cin>>h>>w;
  vector<string> g(h);
  ll cnt=0;
  rep(i,0,h){
    cin>>g[i];
    rep(j,0,w){
      if(g[i][j]=='#'){cnt++;}
    }
  }
  if(cnt==h+w-1){
    cout<<"Possible"<<endl;
  }
  else cout<<"Impossible"<<endl;
}

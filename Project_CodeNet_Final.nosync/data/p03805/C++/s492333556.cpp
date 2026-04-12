#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll=long long;
using vec=vector<ll>;
using Graph = vector<vector<ll>>;
#define loop(i,n) for(ll i=0;i<n;i++)
#define Loop(i, m, n) for(ll i = m;i < n;i++)
#define pool(i,n) for(ll i=n-1;i>=0;i--)
#define Pool(i, m, n) for(ll i=n-1;i>=m;i--)
#define MAX 999999999ll
#define MIN -999999999ll
#define setbit bitset<8>
#define flagcount __builtin_popcount
#define flag(x) (1<<x)
#define flagadd(bit,x) bit|=flag(x)
#define flagpop(bit,x) bit&=~flag(x) 
#define flagon(bit,i) bit&flag(i)
#define flagoff(bit,i) !(bit & (1<<i))
#define all(v) v.begin(),v.end()
#define low2way(v,x) lower_bound(all(v),x)
#define high2way(v,x) upper_bound(all(v),x)
#define count2way(v,x) high2way(v,x)-low2way(v,x)
#define lower(v,x) low2way(v,x)-v.begin() //1番左が0、もし見つから無いならｎを出力
#define higher(v,x) high2way(v,x)-v.begin()-1 //1番左が0、もし見つからないならn-1を出力（注意）
#define putout(x) cout<<x<<endl
#define Gput(a,b) G[a].push_back(b)
int main() {
  cout << fixed << setprecision(16);
  ll n,m;
  cin>>n>>m;
  Graph G(n);
  loop(i,m){
    ll a,b;
    cin>>a>>b;
    Gput(a-1,b-1);
    Gput(b-1,a-1);
  }
  vec v(n);
  loop(i,n){
    v[i]=i;
  }
  loop(i,n){
    sort(all(G[i]));
  }
  ll ans=0;
  bool z=true;
  do {
    z=true;
    loop(i,n-1){
      if(!(binary_search(all(G[v[i]]), v[i+1]))){
        z=false;
      }
    }
    if(z)ans++;
  } while (next_permutation(v.begin()+1, v.end()));
  
  
  putout(ans);
}
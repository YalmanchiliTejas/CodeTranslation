#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n,m;
  cin>>n>>m;
  vector<vin> g(n);
  rep(i,0,m){
   int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans=0;
  vector<int> order(n-1);
  for (int i = 0; i < n-1; ++i) order[i] = i+1;
  do {
    //1とorder[0]の間に辺があるか。
    //order[0]とorder[1]の間の辺があるか。...
    bool ok=true;
    auto rs=find(g[0].begin(), g[0].end(), order[0]);
    if(rs==g[0].end()) continue;
    rep(i,0,n-2){
      rs=find(g[order[i]].begin(), g[order[i]].end(), order[i+1]);
      if(rs==g[order[i]].end()) ok=false;
    }
      if(ok)ans++;
    
  } while (next_permutation(order.begin(), order.end()));
          cout<<ans<<endl;
}
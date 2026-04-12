#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const int n_max = 1e5+10;
vector<int> g[n_max];
set<int> used;
bool tot_ok = true;

void dfs(int cv, int pv){
  // cout << cv << " " << pv << endl;
  bool ok = false;
  for(auto &nv : g[cv]){
    if(nv == pv) continue;
    dfs(nv,cv);    
  }
  if(used.count(cv)==1){
    ok = true;
  }
  if(!ok){
    if(used.count(pv)==0){
      ok = true;
      used.insert(cv);
      used.insert(pv);
    }
  }

  if(!ok){
    tot_ok = false;
  }

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    --a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  used.insert(-1);
  dfs(0,-1);

  cout << (tot_ok ? "Second" : "First") << endl;


  return 0;
    

}

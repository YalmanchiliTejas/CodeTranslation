#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()   //reverse
#define strall(v) (v).cbegin(),(v).cend() //const_itterator
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
const int INF = 1e8;

Graph G;

void dfs(int v,vector<bool> &seen, int &res){
  bool end = true;
  for(int i=0;i<seen.size();i++) if(!seen[i] && i != v) end = false;
  if(end) {
    res++;
    return;
  }
  seen[v] = true;
  for(auto nv: G[v]){
    if(seen[nv]) continue;
    dfs(nv,seen,res);
  }
  seen[v] = false;
}

int main(){
  int N,M; cin >> N >> M;
  G.assign(N,vector<int>());
  for(int i=0;i<M;i++){
    int a,b;cin >> a >> b,a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> seen(N,false);
  int res = 0;
  dfs(0,seen,res);
  cout << res << endl;
}
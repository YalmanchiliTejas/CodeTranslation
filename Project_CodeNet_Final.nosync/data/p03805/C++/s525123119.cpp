#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int N,M;
vector<vector<int>>G;
vector<bool>seen;

int dfs(int now){
  bool ok=true;
  for(int i=0;i<N;i++){
    if(seen[i]==false){ok=false;}
  }
  if(ok){return 1;}
  
  int cnt=0;
  for(int next:G[now]){
    if(seen[next]){continue;}
    seen[next]=true;
    cnt+=dfs(next);
    seen[next]=false;
  }
  return cnt;
}

int main() {
  cin>>N>>M;
  G.resize(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  seen.resize(N,false);
  seen[0]=true;
  cout<<dfs(0)<<endl;
  return 0;
}

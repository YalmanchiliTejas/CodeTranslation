#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> G[10];
typedef pair<int,int> P;
map<P,int> S[10];
map<P,int> E;
int n,m,ans;
int dfs(int v,int eb=0,int vb=1){
  //cout<<v<<" "<<vb<<" "<<(1<<n)-1<<endl;
  if(vb+1==1<<n) return 1;
  if(S[v].count(P(eb,vb))) return S[v][P(eb,vb)];
  int res=0;
  for(int i=0;i<(int)G[v].size();i++){
    if(vb>>G[v][i]&1) continue;
    int k=E[P(v,G[v][i])];
    if(eb>>k&1) continue;
    res+=dfs(G[v][i],eb+(1<<k),vb+(1<<G[v][i]));
  }
  //cout<<v<<" "<<res<<endl;
  return S[v][P(eb,vb)]=res;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
    E[P(a,b)]=E[P(b,a)]=i;
  }
  cout<<dfs(0)<<endl;
  return 0;
}

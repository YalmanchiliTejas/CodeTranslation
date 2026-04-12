#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef pair<int,int> P;
#define MAX 11451
vector<P> G[MAX];
vector<int> E[MAX];
map<int,int> M[MAX];
int ans[MAX];
int idx;
int dfs(int v,int p){
  int res=0;
  E[v].resize(G[v].size());
  for(int i=0;i<(int)G[v].size();i++){
    P e=G[v][i];
    int u=e.first,c=e.second;
    if(u==p) continue;
    int tmp=dfs(u,v)+c;
    E[v][i]=tmp;
    M[v][tmp]++;
    res=max(res,tmp);
  }
  return res;
}
void dfs2(int v,int p,int d){
  int res=d;
  M[v][d]++;
  for(int i=0;i<(int)G[v].size();i++){
    P e=G[v][i];
    int u=e.first,c=e.second;
    if(u==p) continue;
    res=max(res,E[v][i]);
    M[v][E[v][i]]--;
    if(M[v][E[v][i]]==0)
      M[v].erase(M[v].find(E[v][i]));
    int tmp=(--M[v].end())->first;
    dfs2(u,v,tmp+c);
    M[v][E[v][i]]++;
  }
  ans[v]=res;
}
signed main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int s,t,w;
    //cin>>s>>t>>w;
    scanf("%d %d %d",&s,&t,&w);
    G[s].push_back(P(t,w));
    G[t].push_back(P(s,w));
  }
  dfs(0,-1);
  dfs2(0,-1,0);
  for(int i=0;i<n;i++) cout<<ans[i]<<endl;
  return 0;
}
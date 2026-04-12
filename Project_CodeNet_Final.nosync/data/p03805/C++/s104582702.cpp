#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
using namespace std;
int n,m;
vector<vector<int> >E(100);
int ans=0;
void dfs(int now,int visited){
  if(visited==(1<<n)-1){
    ans++;
    return;
  }
  for(int i=0;i<E[now].size();i++){
    if(!((1<<E[now][i])&visited))
      dfs(E[now][i],visited+(1<<E[now][i]));
  }
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    a--;b--;
    E[a].pb(b);
    E[b].pb(a);
  }
  dfs(0,1);
  cout<<ans<<endl;
  return 0;
}

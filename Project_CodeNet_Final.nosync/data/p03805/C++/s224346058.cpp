#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int g[9][9];
int main(){
  int n,m;
  cin>>n>>m;
  while(m--){
    int u,v;
    cin>>u>>v;
    g[--u][--v]=1;
    g[v][u]=1;
  }
  int p[10];
  iota(p+1,p+n,1);
  int ans=0;
  do{
    bool ok=true;
    p[0]=0;
    for(int i=1;i<n;i++)if(!g[p[i]][p[i-1]]){
      ok=false;
    }
    if(ok)ans++;
  }while(next_permutation(p+1,p+n));
  cout<<ans<<endl;
  return 0;
}

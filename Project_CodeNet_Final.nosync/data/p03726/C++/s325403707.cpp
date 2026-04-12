#include <bits/stdc++.h>
using namespace std;

bool F;
vector<int> e[100000];

bool dfs(int i,int p)
{
  int t=0;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    if(dfs(j,i)){
      t++;
    }
  }
  //printf("%d %d %d\n",i,t,F);
  if(t==0){
    return 1;
  }
  else if(t==1){
    return 0;
  }
  F=1;
  return 0;
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int r;
  for(int i=0;i<n;i++){
    if(e[i].size()==1){
      r=i;
      break;
    }
  }
  F=0;
  bool t=dfs(0,-1);
  puts(F||t?"First":"Second");
  return 0;
}

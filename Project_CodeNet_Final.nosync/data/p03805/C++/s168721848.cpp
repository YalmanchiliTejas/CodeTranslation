#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
vector<int>v[11];
int n,m,x,y,a[11];
int dfs(int x,int d){//cout<<v[x].size()<<endl;
  if(d==n)return 1;
  int res=0;
  a[x]=1;
  r(i,v[x].size()){
    if(!a[v[x][i]]){
      a[v[x][i]]=1;
      res+=dfs(v[x][i],d+1);
      a[v[x][i]]=0;
    }
  }
  return res;
}
main(){
  cin>>n>>m;
  r(i,m){
    cin>>x>>y;
    x--,y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cout<<dfs(0,1)<<endl;
}
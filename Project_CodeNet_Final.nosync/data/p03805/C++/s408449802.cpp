#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;cin>>n>>m;
  int path[n+1][n+1];
  for(int i=0;i<n+1;i++)for(int j=0;j<n+1;j++) path[i][j]=0;
  for(int i=0;i<m;i++){
      int a,b;cin>>a>>b;
      path[a-1][b-1]=1;path[b-1][a-1]=1;
  }
  std::vector<int> v;
  for(int i=0;i<n;i++) v.push_back(i);
  int res=0;
  do{
      bool flag=true;
      for(int i=0;i<n-1;i++){
          if(!path[v[i]][v[i+1]]) flag=false;
      }
      if(flag) res++;
  }while(next_permutation(v.begin()+1,v.end()));
  cout<<res<<endl;
}

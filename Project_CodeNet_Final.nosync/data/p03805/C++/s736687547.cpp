#include<bits/stdc++.h>
using namespace std;
bool bo[9];
int n,m;
int a[30],b[30];
int d[9][9];
int dfs(int s,int c){
  if(bo[s])return 0;
  if(c==n)return 1;
  
  bo[s]=true;
  int ret=0;
  for(int i=1;i<=n;i++){
    if(d[s][i]==1){
      ret+=dfs(i,c+1);
    }
  }
  bo[s]=false;
  return ret;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<9;i++)for(int j=0;j<9;j++)d[i][j]=0;
  for(int i=0;i<9;i++)bo[i]=false;
  for(int i=0;i<m;i++){
    cin>>a[i]>>b[i];
    d[a[i]][b[i]]=1;
    d[b[i]][a[i]]=1;
  }
  cout<<dfs(1,1)<<endl;
}
  
  
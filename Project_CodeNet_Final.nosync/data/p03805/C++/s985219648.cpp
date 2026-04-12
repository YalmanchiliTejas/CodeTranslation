#include<bits/stdc++.h>
using namespace std;
int i,j,n,a,b,m,c;
int main(){
  cin>>n>>m;
  vector<vector<int>> d(n,vector<int>(n));
  for(i=0;i<n;i++)for(j=0;j<n;j++)d[i][j]=0;
  for(i=0;i<m;i++)cin>>a>>b,a--,b--,d[a][b]=1,d[b][a]=1;
  vector<int> o(n);
  for(i=0;i<n;i++)o[i]=i;
  do{
    bool res;
    for(res=true,i=1;i<n;i++)if(d[o[i]][o[i-1]]==0)res=false;
    if(res)c++;
  }while(next_permutation(o.begin()+1,o.end()));
  cout<<c;
}
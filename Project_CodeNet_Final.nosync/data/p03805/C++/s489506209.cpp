#include<bits/stdc++.h>
using namespace std;
int mm[9];
vector<int>cs[35];
int sai(int n,int mx){
  if(mx<=0){
    return 1;
  }
  int fl=0;
  for(int i=0;i<cs[n].size();i++){
    if(mm[cs[n][i]]==0){
      mm[cs[n][i]]=1;
      fl+=sai(cs[n][i],mx-1);
      mm[cs[n][i]]=0;
    }
  }
  return fl;
}
int main(){
  int n,m;
  cin>>n>>m;
  int a,b;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    cs[a].push_back(b);
    cs[b].push_back(a);
  }
  mm[1]=1;
  cout<<sai(1,n-1)<<endl;;
  return(0);
}

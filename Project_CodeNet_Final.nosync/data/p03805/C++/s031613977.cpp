#include <bits/stdc++.h>
using namespace std;
int N,M;
int ans=0;
vector<int> connect[8];
int passed[8]={0};
int node=0;
int check(int n){
  passed[n]=1;
  node++;
  if(node==N){
    ans++;
  }
  for(int i=0;i<connect[n].size();i++){
    if(passed[connect[n][i]]==0){
      check(connect[n][i]);
    }
  }
  passed[n]=0;
  node--;
  return 0;
}
 
int main(){
  
  cin>>N>>M;
  vector<int> a(M),b(M);
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    connect[a[i]-1].push_back(b[i]-1);
    connect[b[i]-1].push_back(a[i]-1);
  }
  check(0);
  cout<<ans<<endl;
  
 
  return 0;
}
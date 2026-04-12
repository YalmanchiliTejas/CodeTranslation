#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  int a,b;

  bool ok;
  int ans=0;
  cin>>n>>m;
  int ed[n][n]={};
  vector<int>v(n);
  for(int i=0;i<m;i++){
    cin>>a>>b;
    ed[a-1][b-1]=1;
    ed[b-1][a-1]=1;  
  }
  for(int i=0;i<n;i++){
    v.at(i)=i;
  }
  sort(v.begin(), v.end());

  do{
    ok=true;
    if(v.at(0)!=0)continue;
    for(int i=1;i<n;i++){
      a=v[i-1];
      b=v[i];
      if(!ed[a][b])ok=false;
    }
    if(ok) ans++;
    
    
  }while(next_permutation(v.begin(), v.end()));
  cout<<ans;
  
}
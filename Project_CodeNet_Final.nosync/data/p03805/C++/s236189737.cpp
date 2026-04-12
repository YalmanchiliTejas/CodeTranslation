#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool  abc[8][8];

int dfs(int a,int b,bool c[8]){
  
  bool abcd=true;
  
  for(int i=0;i<b;i++){
    if(c[i]==false)
      abcd=false;
  }
  if(abcd){
    return 1;
  }
  int d=0;
  for(int i=0;i<b;i++){
    if(abc[a][i]==false)continue;
    if(c[i])continue;
    
    c[i]=true;
    
    d+=dfs(i,b,c);
    
    c[i]=false;
  }
  return d;
}
int main(){
  int e,f;
  cin >> e >> f;
  int g[f],h[f];
  for(int i=0;i<f;i++){
    cin >> g[i] >> h[i];
    abc[g[i]-1][h[i]-1] = abc[h[i]-1][g[i]-1] = true;
  }
  
  bool c[8];
  
  for(int i=0;i<e;i++){
    c[i]=false;
  }
  
  c[0]=true;
  cout << dfs(0,e,c)<<endl;
  
  return 0;
}

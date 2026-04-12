#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<bool>> g(10,vector<bool>(10,false));
  for(int i=0;i<m;i++){
    int from,to;
    cin >> from >> to;
    from--;
    to--;
    g[from][to]=true;
    g[to][from]=true;
  }
  vector<int> p(n);
  for(int i=0;i<n;i++){
    p[i]=i;
  }
  int ans=0;
  do{
    bool flag=true;
    for(int i=0;i<n-1;i++){
      if(!g[p[i]][p[i+1]]){
        flag=false;
        break;
      }
      else if(p[0]!=0){
        flag=false;
        break;
      } 
    }
    if(flag) ans++;
  }while(next_permutation(p.begin(),p.end()));
  cout << ans << endl;
}

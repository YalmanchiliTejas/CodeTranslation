#include <bits/stdc++.h>
using namespace std;
const int nmax=8;
vector<bool> used(nmax);
vector<vector<bool>> connect(nmax,vector<bool>(nmax));
int n,m;
int dfs(int now,int depth){
  if(used[now]){
    return 0;
  }
  if(depth==n){
    return 1;
  }
  used[now]=true;
  int ans=0;
  for(int i=0;i<n;i++){
    if(connect[now][i]){
      ans+=dfs(i,depth+1);
    }
  }
  used[now]=false;
  return ans;
}     

int main(){
  cin >> n >> m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    connect[a[i]][b[i]]=connect[b[i]][a[i]]=1;
  }
  cout << dfs(0,1) << endl;
}
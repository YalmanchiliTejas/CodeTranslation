#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int N,M,ans(0);
vector <int> connect[8];
int passed[8]={0};

int dfs(int n){
  passed[n]=1;
  bool finish(true);
  for (int i(0);i<N;i++){
    // cout << passed[i]<<" ";
    if (passed[i]==0) finish=false;
  }
  cout<<endl;
  if (finish==true) ans+=1;
  for (int i(0);i<connect[n].size();i++){
    if (passed[connect[n][i]]==0) dfs(connect[n][i]); // is not still path
  }
  passed[n]=0;
  return 0;
}

int main() {
  cin>>N>>M;
  for (int i(0);i<M;i++) {
    int a,b;
    cin>>a>>b;
    connect[b-1].push_back(a-1);
    connect[a-1].push_back(b-1);
  }
  dfs(0);
  cout<<ans<<endl;
  return 0;
}

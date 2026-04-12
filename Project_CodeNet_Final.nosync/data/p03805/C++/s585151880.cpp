#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> to[10];
vector<int> past;
int n,m;
int ans;

void dfs(int v){
  for(auto x : to[v]){
    if(past[x] == 1)continue;
    past[x]=1;
    dfs(x);
    past[x]=0;
  }
  bool flag=1;
  rep(i,n){
    if(past[i]==0)flag=0;
  }
  if(flag)ans++;
  return;
}

int main(){
  cin>>n>>m;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  past.resize(n,0);
  past[0]=1;
  ans=0;
  dfs(0);
  cout<<ans<<endl;
}
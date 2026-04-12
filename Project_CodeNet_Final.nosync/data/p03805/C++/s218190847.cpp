//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

using namespace std;
using ll=long long;
int res=0;

void dfs(vector<vector<int>> adj,int index,vector<bool> th){
  th[index]=true;
  for(int i=0;i<adj[index].size();i++){
    if(th[adj[index][i]])continue;
    dfs(adj,adj[index][i],th);
  }
  bool b=true;
  for(int i=0;i<th.size();i++)
    b&=th[i];
  if(b)res++;
  th[index]=false;
}

void solve(){
  int num,m;
  cin >> num >> m;
  vector<vector<int>> adj(num,vector<int>(num));
  while(m--){
    int a,b;
    cin >> a >> b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<bool> th(num);
  dfs(adj,0,th);
  cout << res << endl;
}

int main(){
  solve();
  return 0;
}

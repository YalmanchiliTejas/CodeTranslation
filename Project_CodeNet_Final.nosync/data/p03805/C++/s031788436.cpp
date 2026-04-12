#include <bits/stdc++.h>
using namespace std;

void dfs(int N,vector<vector<int>> ed,stack<pair<int,vector<int>>> s,int &ans){
  if(s.empty()==false){
    int ve=s.top().first;vector<int> arc=s.top().second;
    arc[ve]=1;s.pop();
    bool b=true;
    for(int i=0; i<N; i++){
      if(arc[i]==0){
        b=false;break;
      }
    }
    if(b) ans++;
    else{
      for(int i=0; i<ed[ve].size(); i++){
        if(arc[ed[ve][i]]==0){
          s.push(make_pair(ed[ve][i],arc));dfs(N,ed,s,ans);
        }
      }
    }
  }
}

int main(){
  int N,M;cin >> N >> M;
  vector<vector<int>> ed(N);
  for(int i=0;i<M;i++){
    int a,b;cin >> a >> b;
    ed[a-1].push_back(b-1);ed[b-1].push_back(a-1);
  }
  int ans=0;
  vector<int> arc(N,0);
  stack<pair<int,vector<int>>> s;s.push(make_pair(0,arc));
  dfs(N,ed,s,ans);
  cout << ans << endl;
}
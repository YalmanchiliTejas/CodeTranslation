#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 30;
set<int> adj[maxn];

int main(){
  int n; cin >> n;
  for(int i=0;i<n-1;i++){
    int a,b; cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  vector<int> Q;
  for(int i=1;i<=n;i++){
    if(adj[i].size() == 1){
      Q.push_back(i);
    }
  }
  while(!Q.empty()){
    int v = Q.back(); Q.pop_back();
    //cout << v << "!\n";
    int u = *adj[v].begin();
    for(int w : adj[u]){
      if(w == v) continue;
      adj[w].erase(adj[w].find(u));
      if(adj[w].size() == 0){
	cout << "First\n";
	return 0;
      }
      if(adj[w].size() == 1){
	Q.push_back(w);
      }
    }
  }
  cout << "Second\n"; 
}

#include <bits/stdc++.h>
#define _for(i,n) for(int i = 0; i < n; i++)

using namespace std;
void dfs(int,vector<vector<int> >,int*);


int ans = 0;
int n,m;
int main() {
  cin >> n >> m;
  int a[m], b[m];
  _for(i,m) cin >> a[i] >> b[i];
  _for(i,m) {
    a[i]--;
    b[i]--;
  }
  int visited[n];
  _for(i,n) visited[i] = 0;
  vector<vector<int> > connected(n,vector<int>());
  _for(i,m) {
    connected[a[i]].push_back(b[i]);
    connected[b[i]].push_back(a[i]);
  }
  dfs(0,connected,visited);
  cout << ans << endl;  
  return 0;
}

int visited_all(int* visited) {
  int all_visited = true;
  _for(i,n) if (visited[i]!=1) all_visited = false;
  return all_visited;
}

void dfs(int current,vector<vector<int> > connected,int* visited) {
  visited[current] = 1;
  if (visited_all(visited)) ans++;
  else {
    _for(i,connected[current].size()) if (visited[connected[current][i]]!=1) {
      dfs(connected[current][i],connected,visited);
    }
  }
  visited[current] = 0;
}
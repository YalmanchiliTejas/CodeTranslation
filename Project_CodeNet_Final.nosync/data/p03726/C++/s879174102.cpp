#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> G[100001];
bool used[100001];
bool ans = true;
bool match[100001];

void  dfs(int v, int par) {
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++) {
    if(used[G[v][i]])continue;	       		      	      
    dfs(G[v][i],v);
    
  }
  if(!match[v] && !match[par]) match[v] = match[par] = true;
  return;
}
    

int main() {
  cin >> N;

  

  for(int i = 0; i < N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  if(N % 2 == 1){ cout <<"First" <<endl; return 0; }
  dfs(0,-1);

  for(int i = 0; i < N; i++) {
    if(!match[i]) {ans = false; break;}
    }

  if(!ans) cout <<"First"<< endl;
  else cout << "Second" <<endl;
  
}

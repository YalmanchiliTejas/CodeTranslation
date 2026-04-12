#include <iostream>
#include <vector>
using namespace std;
int N,M,a,b;
vector<vector<bool>> path;
vector<bool> passed;

int dfs(int now, int depth) {
  if(passed[now]) return 0;
  if(depth == N) return 1;
  passed[now] = true;
  int ans = 0;
  for(int i = 0; i < N; i++){
    if(path[now][i]) ans += dfs(i, depth+1);
  }
  passed[now] = false; // set false again for reuse
  return ans;
}


int main() {
  cin >> N >> M;
  path = vector<vector<bool>>(N, vector<bool>(N, false));
  passed = vector<bool>(N, false);
  while(cin >> a >> b) {
  	path[a-1][b-1] = path[b-1][a-1] = true;
  	// 0から始まるように-1した
  }
  cout << dfs(0, 1);
}
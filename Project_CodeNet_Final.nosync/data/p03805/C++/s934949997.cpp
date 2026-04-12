#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
int A[8][8];
int N, M;

int dfs(int idx, vector<bool> visited){
  visited[idx] = true;
  for(int i=0; i< N; i++){
    if (!visited[i]) break;
    if (i==N-1) return 1;
  }
  int ans = 0;
  for(int next=0; next<N; next++){
    if(A[idx][next] && !visited[next]){
      ans += dfs(next, visited);
    }
  }
  
  return ans;
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b;
  	cin >> a >> b;
  	a--;b--;
    A[a][b] = 1;
    A[b][a] = 1;
  }
  
  vector<bool> visited(N);
  visited[0] = true;
  int res = dfs(0, visited);
  
  cout << res << endl;
}

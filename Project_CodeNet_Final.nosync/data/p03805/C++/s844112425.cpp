#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  vector<vector<bool>> adj(N, vector<bool>(N, false));
  for(int m = 0; m < M; m++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a][b] = true;
    adj[b][a] = true;
  }

  long long ans = 0;
  vector<int> path(N);
  for(int i = 0; i < N; i++){
    path[i] = i;
  }
  do{
    if(path[0] != 0){
      continue;
    }
    bool ok = true;
    for(int i = 0; i + 1 < N; i++){
      if(!adj[path[i]][path[i + 1]]){
        ok = false;
      }
    }
    if(ok){
      ans++;
    }
  }while(next_permutation(path.begin(), path.end()));
  cout << ans << endl;
}


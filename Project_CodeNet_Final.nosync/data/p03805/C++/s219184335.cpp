#include <iostream>
#include <vector>

using namespace std;

vector<int> G[9];
int N, M;

int solve2(int s, vector<int> state){
  int result = 0;
  int ok = 1;
  for(int i = 1; i <= N; i++){
    if(state[i] == 0){
      ok = 0;
      break;
    }
  }
  if(ok == 1) return 1;

  for(int i = 0; i < G[s].size(); i++){
    int to = G[s][i];
    if(state[to] == 1)  continue;
    else {
      vector<int> state2(state);
      state2[to] = 1;
      result += solve2(to, state2);
    }
  }
  return result;
}

void solve(){
  vector<int> state(9, 0);
  state[1] = 1;
  cout << solve2(1, state) << endl;
}


int main(){
  cin >> N >> M;

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  solve();

}

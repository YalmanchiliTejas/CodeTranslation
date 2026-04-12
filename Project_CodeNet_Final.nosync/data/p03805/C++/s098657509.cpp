#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;

const int nmax = 8;
const vector<bool> all_visited = {1, 1, 1, 1, 1, 1, 1, 1, 1};
vector<vector<bool>> graph(nmax, vector<bool>(nmax));
vector<bool> visited = {1, 1, 1, 1, 1, 1, 1, 1, 1};

int N, M;



int DFS(int v){

  int ans = 0;

  if(visited == all_visited){
    return 1;
  }

  rep(i, N){
      if (graph.at(v-1).at(i) == true && visited.at(i) == false){
        visited.at(i) = true;
        ans += DFS(i+1);
        visited.at(i) = false;
      }
  }

  return ans;

}

int main() {
  cin >> N >> M;

  rep(i, M){
    int a, b;
    cin >> a >> b;
    graph.at(a-1).at(b-1) = true;
    graph.at(b-1).at(a-1) = true;
  }

  rep(j, N){
    visited.at(j) = false;
  }

  visited.at(0) = true;
  cout << DFS(1) << endl;

}

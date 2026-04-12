#include <bits/stdc++.h>
using namespace std;

int main() {
  using graph= vector<vector<int>>;

  int N,M;
  cin >> N >> M;

  graph G(N, vector<int>(N));
  for(int i=0; i<M; i++){
    int x,y;
    cin >> x >> y;
    x--; y--; // 1-indexed -> 0-indexed

    G.at(x).at(y)= 1;
    G.at(y).at(x)= 1;
  }

  vector<int> path;
  for(int i=0; i<N; i++){
    path.push_back(i);
  }

  int cnt= 0;
  do{
    bool connected= true;
    for(int i=0; i<N-1; i++){
      if( G.at(path.at(i)).at(path.at(i+1))==0 ){
        connected= false;
        break;
      }
    }
    if(connected) cnt++;
  } while( next_permutation(path.begin()+1, path.end()) );

  cout << cnt << endl;
}
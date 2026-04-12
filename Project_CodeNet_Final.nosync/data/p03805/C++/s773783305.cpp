#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  vector<vector<bool>> connection(8, vector<bool> (8));
  for (int i=0; i<M; i++){
    int x, y;
    cin >> x >> y;
    connection.at(x-1).at(y-1)=connection.at(y-1).at(x-1)=true;
  }
  
  vector<int> pattern(N);
  for (int i=0; i<N; i++){
    pattern.at(i)=i;
  }
  
  int cnt = 0;
do {
  bool visited_all = true;
  for (int i=1; i<N; i++){
    int x = pattern.at(i-1);
    int y = pattern.at(i);
    if (!connection.at(x).at(y)) {
      visited_all = false;
      break;
    } 
  }
  if (visited_all && pattern.at(0) == 0) {cnt += 1;}
} while (next_permutation(pattern.begin(), pattern.end()));
  
  cout << cnt << endl;
}
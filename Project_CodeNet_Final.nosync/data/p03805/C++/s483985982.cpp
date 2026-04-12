#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, count = 0; cin >> N >> M;
  vector<vector<bool>> path(N, vector<bool> (N, false));
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    path.at(a).at(b) = true;
    path.at(b).at(a) = true;
  }
  vector<int> route(N);
  for(int i = 0; i < N; i++) route.at(i) = i;
  sort(route.begin(), route.end());
  do {
    bool judge = true;
    if(route.at(0) != 0) continue;
    for(int i = 1; i < N; i++) {
      if(!path.at(route.at(i - 1)).at(route.at(i))) {
        judge = false;
        break;
      }
    }
    if(judge) count++;
  } while(next_permutation(route.begin(), route.end()));
  cout << count << endl;
}
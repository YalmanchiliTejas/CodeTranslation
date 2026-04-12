#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, M; char c; cin >> c >> M;
  N = (int)(c - '0'); //cout << N << " " << M << " " << c << endl;
  vector<vector<bool>> path(N, vector<bool> (N, false));
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    path.at(a).at(b) = true;
    path.at(b).at(a) = true;
  }
  vector<string> paths(0), DFS(1, "1");
  bool judge = false;
  for(int i = 0; i < DFS.size(); i++) {
    for(char j = '2'; j <= c; j++) {
      string s = DFS.at(i);
      if(s.find(j) == string::npos) {
        s += j;
        DFS.push_back(s);
        if(s.size() == N) {
          paths.push_back(s);
        }
      }
    }
  }
  int count = 0;
  for(int i = 0; i < paths.size(); i++) {
    bool j2 = true;
    for(int j = 1; j < N; j++) {
      int x = (int)(paths.at(i).at(j - 1) - '1');
      int y = (int)(paths.at(i).at(j) - '1');
      if(path.at(x).at(y)) continue;
      else {
        j2 = false;
        break;
      }
    }
    if(j2) count++;
  }
  cout << count << endl;
}
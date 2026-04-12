#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> res;
  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    if (str == string(M, '.')) continue;
    res.push_back(str);
  }
  
  for (int j = 0; j < res[0].size(); ++j) {
    bool all = true;
    for (int i = 0; i < res.size(); ++i) {
      if (res[i][j] != '.') all = false;
    }
    if (all) {
      for (int i = 0; i < res.size(); ++i) {
       	res[i].erase(res[i].begin() + j); 
      }
      --j;
    }
  }
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << endl;
  }
}
    
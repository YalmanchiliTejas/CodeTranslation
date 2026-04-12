#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

vector<vector<int>> e;

int solve(vector<int> arrived, int c) {
  arrived[c] = 1;

  int sum = accumulate(arrived.begin(), arrived.end(), 0);
  if (sum == arrived.size()) return 1;

  int res = 0;
  for (int i=0; i < arrived.size(); i++) {
    if (arrived[i] == 1) continue;
    // cout << i << endl;
    if (e[c][i] != 0) res += solve(arrived, i);
  }

  return res;
}

int main() {
  int N, M;
  cin >> N >> M;
  e = vector<vector<int>>(N,vector<int>(N, 0));

  
  for (int i=0; i<M; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    e[a][b] = 1;
    e[b][a] = 1;
  }

  vector<int> v(N, 0);
  v[0] = 1;
  cout << solve(v, 0) << endl;
}

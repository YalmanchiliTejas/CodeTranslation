#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> perms;

void add_perms(vector<int> perm, vector<bool> can_use) {
  if (none_of(can_use.begin(), can_use.end(), [](bool b){ return b; })) {
    perms.push_back(perm);
  } else {
    for (auto it = can_use.begin(); it != can_use.end(); it++) {
      if (*it) {
        int dist = distance(can_use.begin(), it);
        vector<int> new_perm(perm);
        new_perm.push_back(dist);
        vector<bool> new_can_use(can_use);
        new_can_use[dist] = false;
        add_perms(new_perm, new_can_use);
      }
    }
  }
}

int main() {
  int N, M; cin >> N >> M;
  bool E[N][N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      E[i][j] = false;
  for (int i = 0; i < M; i++) {
    int x, y; cin >> x >> y; x--; y--;
    E[x][y] = E[y][x] = true;
  }
  vector<bool> can_use_init = vector<bool>(N, true);
  can_use_init[0] = false;
  add_perms(vector<int>(1, 0), can_use_init);
  int c = 0;
  for (auto it = perms.begin(); it != perms.end(); it++) {
    vector<int> perm = *it;
    bool valid_path = true;
    for (int i = 0; i < N-1; i++) {
      if (!E[perm[i]][perm[i+1]]) valid_path = false;
    }
    c += valid_path;
  }
  cout << c << endl;
}
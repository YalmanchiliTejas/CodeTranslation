#include <iostream>

using namespace std;

void failure () {
  cout << "Impossible" << endl;
  exit(0);
}

const int MAX_N = 20;

char grid [MAX_N][MAX_N];

int ni [4] = {1, 0, -1, 0};
int nj [4] = {0, 1, 0, -1};

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!(i == 1 && j == 1) && !(i == n && j == m)) {
        if (grid[i][j] == '#') {
          int pc = 0;
          for (int k = 0; k < 2; k++) {
            if (grid[i + ni[k]][j + nj[k]] == '#') pc++;
          }

          int nc = 0;
          for (int k = 2; k < 4; k++) {
            if (grid[i + ni[k]][j + nj[k]] == '#') nc++;            
          }

          if (pc != 1 || nc != 1) failure();
        }
      }

      if (i == 1 && j == 1) {
        int pc = 0;
        for (int k = 0; k < 2; k++) {
          if (grid[i + ni[k]][j + nj[k]] == '#') pc++;
        }

        if (pc != 1) failure();
      }

      if (i == n && j == m) {
        int nc = 0;
        for (int k = 2; k < 4; k++) {
          if (grid[i + ni[k]][j + nj[k]] == '#') nc++;            
        }

        if (nc != 1) failure();
      }
    }
  }

  cout << "Possible" << endl;
}

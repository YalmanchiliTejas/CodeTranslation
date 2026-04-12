#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
  int n, m; cin >> n >> m;
  vector<bool> row(n, false), col(m, false);
  vector< vector<char> > table(n, vector<char> (m, 0));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> table[i][j];
      if(table[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }

  for(int i = 0; i < n; ++i) {
    if(!row[i]) continue;
    for(int j = 0; j < m; ++j) {
      if(!col[j]) continue;
      cout << table[i][j];
    }
    cout << endl;
  }
  return 0;
}

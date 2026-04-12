#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
const ll INFll = 1ll << 60;

int main() {
  int h, w;
  cin >> h >> w;
  set<int> H;
  set<int> W;
  vector<vector<char>> A(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char a;
      cin >> a;
      A[i][j] = a;
      if (a == '#') {
        H.insert(i);
        W.insert(j);
      }
    }
  }

  for (int i : H) {
    for (int j : W) {
      cout << A[i][j];
    }
    cout << endl;
  }

  return 0;
}

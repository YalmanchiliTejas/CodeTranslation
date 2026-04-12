#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> P;
struct pos {
  int row;
  int column;
};
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1 << 30;
const ll MOD = 1000000007;
int main(void) {
  int N, M;
  bool d[10][10];
  memset(d, 0, sizeof(d));
  vector<int> val;
  cin >> N >> M;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    d[a][b] = true;
    d[b][a] = true;
  }

  rep(i, N) { val.push_back(i + 1); }

  Sort(val);

  int count = 0;

  do {
    if (val[0] != 1) continue;

    bool find = true;
    for (int i = 0; i < val.size() - 1; i++) {
      if (d[val[i]][val[i + 1]]) continue;
      find = false;
      break;
    }

    if (find) {
      count++;
    }

  } while (next_permutation(val.begin(), val.end()));

  cout << count << endl;

  return 0;
}
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
struct pos {
  int row;
  int column;
};
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1 << 30;
const ll MOD = 1000000007;
int N, M;
vector<vector<bool>> keep;
vector<int> pattern;

bool isValid(void) {
  rep(i, N - 1) {
    if (!keep[pattern[i]][pattern[i + 1]]) return false;
  }
  return true;
}
int main(void) {
  cin >> N >> M;
  keep.resize(N);
  rep(i, N) {
    keep[i].resize(N);
    pattern.push_back(i);
  }
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    keep[a - 1][b - 1] = true;
    keep[b - 1][a - 1] = true;
  }

  int count = 0;
  Sort(pattern);

  do {
    if (pattern[0] != 0) break;
    if (isValid()) count++;
  } while (next_permutation(pattern.begin(), pattern.end()));
  cout << count << endl;
  return 0;
}
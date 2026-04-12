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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1 << 30;
const ll MOD = 1000000007;
int N = 0;
int M = 0;
vector<int> path;
int main(void) {
  cin >> N >> M;
  path.resize(N);
  for (int i = 0; i < N; i++) path[i] = i;

  int val[10][10] = {};
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    val[a - 1][b - 1] = 1;
    val[b - 1][a - 1] = 1;
  }

  Sort(path);

  int count = 0;
  do {
    int c = 0;
    if (path[0] != 0) break;
    for (int i = 0; i < N - 1; i++) {
      if (val[path[i]][path[i + 1]] != 0) c++;
    }
    if (c == N - 1) count++;
  } while (next_permutation(path.begin(), path.end()));
  cout << count << endl;
  return 0;
}
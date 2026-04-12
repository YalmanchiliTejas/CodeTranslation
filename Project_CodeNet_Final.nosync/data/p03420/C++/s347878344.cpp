#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using ll = long long int;
using P = pair<int, int>;
using edge = struct {
  int to;
  int cost;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int N, K;
  cin >> N >> K;
  ll c = 0;
  for (int b = K + 1; b <= N; b++) {
    int p = floor(N / b);
    c += p * max(0, b - K) + max(0, (N % b) - K + 1);
    if (K == 0)
      c--;
  }
  cout << c << endl;

  return 0;
}
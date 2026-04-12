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
#define rep(n) for (int i = 0; i < (n); i++)

using namespace std;
using ll = long long int;
using P = pair<int, int>;
using edge = struct {
  int to;
  int cost;
};
using namespace std;

int main() {
  long long int N, tmp;
  vector<long long int> X;
  vector<long long int> Y;
  cin >> N;
  for (ll i = 0; i < N; i++) {
    cin >> tmp;
    X.push_back(tmp);
    Y.push_back(tmp);
  }
  sort(Y.begin(), Y.end());
  long long int x1 = Y[-1 + N / 2];
  long long int x2 = Y[N / 2];
  for (ll i = 0; i < N; i++) {
    if (X[i] <= x1) {
      cout << x2 << endl;
    } else {
      cout << x1 << endl;
    }
  }

  return 0;
}

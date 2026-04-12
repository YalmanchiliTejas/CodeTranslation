#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P;
map<int, int> dp;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> a(5, 0);
  int N, K;
  string S;
  cin >> N;
  cin >> S;
  cin >> K;
  auto target = S[K - 1];
  int i = 0;
  for (auto c : S) {
    if (c != target) {
      S[i] = '*';
    }
    ++i;
  }
  cout << S << endl;
  return 0;
}

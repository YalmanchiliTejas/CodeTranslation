#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, K;
  string S;
  cin >> N >> S >> K;
  char target = S[K - 1];
  for (int i = 0; i < N; i++) {
    if (S[i] != target) {
      cout << "*";
    } else {
      cout << target;
    }
  }
  cout << endl;
  return 0;
}
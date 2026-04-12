#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A,B,C,X,Y;
  std::cin >> A >> B >> C >> X >> Y;
  int loopmax = std::max(X,Y);
  int t = 0;

  int cost = A*X + B*Y;

  while (loopmax >= t/2) {
    t += 2;
    cost = std::min(cost, A*std::max(0,(X-t/2)) + B*std::max(0,(Y-t/2)) + C*t);
  }
  std::cout << cost << '\n';

  return 0;
}

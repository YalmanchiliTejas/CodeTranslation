#include <algorithm>
#include <array>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#define repss(name, start, stop, step) for (int name = start; name < stop; name += step)
#define reps(name, start, stop) repss(name, start, stop, 1)
#define rep(name, stop) reps(name, 0, stop)

using namespace std;

int main() {
  int A, B, C, X, Y;
  scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

  int p1 = min(A + B, 2 * C);
  int p2 = min(A, 2 * C);
  int p3 = min(B, 2 * C);

  int t = min(X, Y);

  X -= t; Y -= t;

  printf("%d\n", X * p2 + Y * p3 + t * p1);
}
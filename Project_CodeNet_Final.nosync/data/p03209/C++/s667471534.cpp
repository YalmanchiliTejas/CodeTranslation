#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

long long mod = 1000000007;

long long find_answer(int N, long long X) {
  if(X == 0) return 0;
  if(N == 0) return 1;  

  long long S = ((1LL << (N + 2)) - 3);
  if(S == X) return (1LL << (N+1)) - 1;

  if(X <= (S/2)) return find_answer(N-1, X-1);
  return (1LL << N) + find_answer(N-1, X - ((1LL << (N+1)) - 3 + 2));
}

int main() {
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);

  int N = 0;
  long long X = 0;

  cin >> N >> X;
  cout << find_answer(N, X);

  return 0;
}

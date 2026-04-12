#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 30;
const int MOD = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  deque<int> a;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (i % 2 == 0) {
      a.push_back(x);
    } else {
      a.push_front(x);
    }
  }
  if (n % 2 == 1) reverse(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], " \n"[i + 1 == n]);
  }
  return 0;
}

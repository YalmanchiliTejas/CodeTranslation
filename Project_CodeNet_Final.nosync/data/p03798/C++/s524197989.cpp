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
#include <functional>
#include <random>
#include <ctime>

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
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;
char s[N];
int ret[N];

bool solve(int n, char s[]) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      ret[0] = i;
      ret[1] = j;
      for (int i = 2; i < n + 2; ++i) {
        if (ret[i - 1]) {
          ret[i] = (s[i - 1] == 'o' ? 1 - ret[i - 2] : ret[i - 2]);
        } else {
          ret[i] = (s[i - 1] == 'o' ? ret[i - 2] : 1 - ret[i - 2]);
        }
      }
      if (ret[0] == ret[n] && ret[1] == ret[n + 1]) return true;
    }
  }
  return false;
}

int main() {
  int n;
  scanf("%d%s", &n, s);
  s[n] = s[0];
  if (!solve(n, s)) {
    puts("-1");
  } else {
    for (int i = 0; i < n; ++i) {
      putchar(ret[i] ? 'W' : 'S');
    }
    puts("");
  }
  return 0;
}

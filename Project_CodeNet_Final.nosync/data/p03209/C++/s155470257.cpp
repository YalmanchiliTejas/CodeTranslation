#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf

int n;
long long x;
long long len[55], p[55];

int main() { 

  cin >> n >> x;

  len[0] = 1; p[0] = 1;
  for (int i = 1; i <= n; i++) {
    len[i] = len[i - 1] * 2 + 3;
    p[i] = p[i - 1] * 2 + 1;
  }

  long long ans = 0;

  while (x > 0 && n >= 0) {
    if (n == 0) {
      ans += 1;
      break;
    }
    long long mid = len[n] / 2 + 1;
    if (x == 1) {
      break;
    }
    if (x == mid) {
      ans += p[n - 1] + 1;
      break;
    }
    if (x == len[n]) {
      ans += p[n];
      break;
    }
    if (x < mid) {
      x--;
      n--;
      continue;
    }
    ans += p[n - 1] + 1;
    x -= len[n - 1] + 2; 
    n--;
  }

  cout << ans << endl;

  return 0;
}

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
#include <chrono>
#include <random>
#include <bitset>

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
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

string s;
int n;
int can;
long long dp[125][2][2][5];

long long calc(int pos, bool started, bool less, int rem) {
  long long &res = dp[pos][started][less][rem];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (pos == n) {
    if (started && rem == 0) {
      res = 1;
    }
    return res;
  }
  int sNum = s[pos] - '0';
  for (int i = 0; i <= 9; i++) {
    if (i != 0 && rem == 0) {
      continue;
    }
    if (!less && i > sNum) {
      continue;
    }
    res += calc(pos + 1, started | (i > 0), less | (i < sNum), rem - (i > 0 ? 1 : 0));
  }

  // cerr << pos << " " << started << " " << less << " " << rem << " " << res << " " << endl;

  return res;
}

int main() { 

  getline(cin, s);
  scanf("%d", &can);
  n = sz(s);

  memset(dp, -1, sizeof(dp));

  cout << calc(0, false, false, can) << endl;

  return 0;
}

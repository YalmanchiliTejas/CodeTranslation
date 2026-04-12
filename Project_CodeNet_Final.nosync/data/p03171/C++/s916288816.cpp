#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <regex>
#include <climits>

#define FOR(i, f, n) for(int (i) = (f), TMPend = (n); (i) < TMPend; (i)++)
#define RFOR(i, f, n) for(int (i) = (f), TMPend = (n); (i) >= TMPend; (i)--)
#define REP(i, n) for(int (i) = 0, TMPend = (n); (i) < TMPend; (i)++)
#define RREP(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define rep(i, n) for(int (i) = 0, TMPend = (n); (i) < TMPend; (i)++)
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define forin(i, a) for(auto i: (a))
#define p(...) printf(__VA_ARGS__); cout << endl;
#define in(...) __VA_ARGS__; input__(__VA_ARGS__);
#define input(...) in(__VA_ARGS__)
#define out(...) output__(__VA_ARGS__);
#define output(...) out(__VA_ARGS__)
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](auto const &a, auto const &b){ return c ;}
#define key(t, x, compare) [](const t &a, const t &b){ return a x compare b x ;}
#define unless(a) if(!(a))

using namespace std;

using pii = pair<int, int>;

template <class... T>
void input__(T &...a) {
  for(auto v: {&a...}) {
    cin >> *v;
  }
}

void output__(){
  cout << endl;
}

template <class Head, class... T>
void output__(Head const &v, T const &...a) {
  if(sizeof...(a) == 0) {
    cout << v;
  } else {
    cout << v << " ";
  }
  output__(a...);
}

int main(){
  int input(n);
  int list_input(a, n);
  long long dp[n + 1][n + 1][2];

  RFOR(l, n, 0) rep(r, n + 1) rep(taro, 2) {
    if (r - l <= 0) {
      dp[l][r][taro] = 0;
      continue;
    }

    long long R;
    if (taro) {
      R = max(
          dp[l + 1][r][!taro] + a[l],
          dp[l][r - 1][!taro] + a[r - 1]);
    } else {
      R = min(
          dp[l + 1][r][!taro] - a[l],
          dp[l][r - 1][!taro] - a[r - 1]);
    }
    dp[l][r][taro] = R;
  }
  out(dp[0][n][1]);
}

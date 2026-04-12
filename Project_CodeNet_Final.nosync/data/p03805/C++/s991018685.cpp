#include <bits/stdc++.h>

#define int long long

#define all(v) v.begin(), v.end()
 
// loop
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 	// a ~ b-1	(ascending)
#define REP(i, n) FOR(i, 0, n)							// 0 ~ n-1
#define NREP(i, n) FOR(i, 1, n + 1)						// 1 ~ n
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)	// a ~ b	(descending)
#define RREP(i, n) RFOR(i, n, 0)						// n ~ 0
#define RNREP(i, n) RFOR(i, n, 1)						// n ~ 1
 
// container operation
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define ASORT(c) std::sort((c).begin(), (c).end())
#define DSORT(c) std::sort((c).begin(), (c).end(), std::greater<typeof((c).front())>())
#define SIZE(x) ((int)(x).size())
 
// debug
#define check(x) std::cout << #x << " = " << x << '\n'
 
// print
#define cout(x) std::cout << (x) << '\n'
 
// type alias
using VI = std::vector<int>;
using VII = std::vector<VI>;
using VB = std::vector<bool>;
using VBB = std::vector<VB>;
using VS = std::vector<std::string>;
using PII = std::pair<int, int>;

std::string yes = "Yes\n";
std::string no = "No\n";

void solve();

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<bool>> A(n, std::vector<bool>(n, false));
  int a, b;
  REP(i, m) {
    std::cin >> a >> b;
    A[a-1][b-1] = true;
    A[b-1][a-1] = true;
  }

  std::vector<int> vec(n);
  REP(i, n) {
    vec.at(i) = i;
  }

  ASORT(vec);
  int sum = 0;
  do {
    bool flag = false;
    if (vec[0] != 0) {
      continue;
    }
    REP (i, n-1) {
      // check(vec.at(i)+1);
      // check(vec.at(i+1)+1);
      if (!A.at(vec.at(i)).at(vec.at(i+1))) {
        // cout("abort");
        flag = true;
        break;
      }
    }
    if (flag) {
      continue;
    }
    sum++;
    // cout("");
  } while (next_permutation(all(vec)));

  cout(sum);
}

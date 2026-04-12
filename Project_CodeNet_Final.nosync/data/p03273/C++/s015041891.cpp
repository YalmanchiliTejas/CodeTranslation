#include <bits/stdc++.h>

#define int long long

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
#define cout(x) std::cout << x << '\n'

// typedef
typedef std::vector<int> VI;
typedef std::vector<VI> VII;
typedef std::vector<std::string> VS;

int SumOfDigits(int x) {
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

void PrintMap(std::map<int, int>& m) {
  for (auto iter: m) {
    std::cout << iter.first << " => " << iter.second << "\n";
  }
}

int Digits(int x) {
  int d = 0;
  while (x > 0) {
    x /= 10;
    d++;
  }
  return d;
}

void solve();

signed main() {
  solve();
  return 0;
}

void solve() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> vec(h);
  REP(i, h) {
    std::cin >> vec.at(i);
  }

  for (int i = 0; i < vec.at(0).size(); i++) {
    bool flag = true;
    for (int j = 0; j < h; j++) {
      if (vec.at(j).at(i) != '.') {
        flag = false;
        break;
      }
    }
    if (flag) {
      for (int j = 0; j < h; j++) {
        std::string s = vec.at(j);
        if (i == w-1) {
          vec.at(j) = s.substr(0, i);
        } else {
          vec.at(j) = s.substr(0, i) + s.substr(i+1);
        }
      }
      i--;
    }
  }

  std::string empty = "";
  REP(i, vec.at(0).size()) {
    empty += ".";
  }

  
  REP(i, h) {
    if (vec.at(i) != empty) {
      std::cout << vec.at(i) << '\n';
    }
  }
}
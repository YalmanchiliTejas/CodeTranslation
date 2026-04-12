#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(long long n, std::vector<std::string> S) {
  vector<map<char, int>> counts;
  for (auto &s : S) {
    map<char, int> m;
    for (auto c : s) {
      m[c]++;
    }
    counts.push_back(m);
  }
  map<char, int> resMap;
  for (int i = 'a'; i <= 'z'; i++) {
    bool valid = true;
    int minVal = INT_MAX;
    for (auto m : counts) {
      if (!m.count(i)) {
        valid = false;
      } else {
        minVal = min(minVal, m[i]);
      }
    }
    if (valid) {
	resMap[i] = minVal;
    }
  }
  string res;
  for (auto elem : resMap) {
    for (int i = 0; i < elem.second; i++) {
	res.push_back(elem.first);
    }
  }
  cout << res << endl;
}

int main() {

  long long n;
  scanf("%lld", &n);
  std::vector<std::string> S(n);
  for (int i = 0; i < n; i++) {
    std::cin >> S[i];
  }
  solve(n, std::move(S));
  return 0;
}

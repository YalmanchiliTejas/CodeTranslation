#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N; cin>>N;
  vector<int> maxes;
  auto find_greater = [&](int n) {
    int l=0, r=maxes.size()-1;
    int res=r+1;
    while (l <= r) {
      auto c = (l+r)/2;
      if (n > maxes[c]) {
        res = c;
        r = c-1;
      } else {
        l = c+1;
      }
    }
    return res;
  };

  for (int i = 0; i < N; i++) {
    int a; cin>>a;
    auto p = find_greater(a);
    if (p == maxes.size()) {
      maxes.push_back(a);
    } else {
      maxes[p] = a;
    }
  }
  cout << maxes.size() << endl;

  return 0;
}

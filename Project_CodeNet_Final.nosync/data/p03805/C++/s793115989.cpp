#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> r;
int n;

int func(int a, vector<int> h) {
  int ret = 0, f = 1;
  for(auto x : r.at(a)) {
    if(!count(h.begin(), h.end(), x)) {
      f = 0;
      auto v = h;
      v.push_back(x);
      ret += func(x, v);
    }
  }
  if(f && h.size() == n)
    return 1;
  return ret;
}

int main() {
  int m, a, b, o = 0;
  cin >> n >> m;
  r = vector<vector<int>>(n);
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    r.at(--a).push_back(--b);
    r.at(b).push_back(a);
  }
  for(auto x : r.at(0)) {
    vector<int> v = {0, x};
    o += func(x, v);
  }
  cout << o << endl;
}
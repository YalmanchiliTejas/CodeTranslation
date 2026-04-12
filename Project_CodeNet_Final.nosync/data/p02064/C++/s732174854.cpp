#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

i64 query(i64 u, i64 v) {
  i64 ans;
  cout << "? " << u << " " << v << endl;
  cin >> ans;
  return ans;
}

int main() {
  i64 N, s, t;
  cin >> N >> s >> t;
  i64 len = query(s, t);
  vector<pair<i64, i64>> vec;
  for(int i = 1;i <= N;i++) {
    i64 a = query(s, i);
    i64 b = query(i, t);
    if(a + b == len) {
      vec.push_back({a, i});
    }
  }
  sort(all(vec));
  vector<i64> ans;
  ans.push_back(vec[0].second);
  i64 now = 0;
  i64 idx = 1;
  while(idx < vec.size()) {
    i64 a = vec[now].second;
    i64 b = vec[idx].second;
    if(vec[now].first + query(a, b) == vec[idx].first) {
      now = idx;
      ans.push_back(b);
    }
    idx++;
  }
  cout << "! ";
  for(int i = 0;i < ans.size();i++) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
}


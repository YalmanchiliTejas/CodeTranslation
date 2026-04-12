#include<bits/stdc++.h>
using namespace std;
int main() {
  using LL = long long;
  int N;
  cin >> N;
  vector<LL> S(N);
  for(auto& s: S) cin >> s;
  LL res = 0;
  for(auto d=1; d<N; ++d) {
    unordered_set<int> used;
    LL sum = 0;
    for(auto i=0; i<N; i+=d) {
      auto j = N-1 - i;
      used.emplace(i);
      if(used.count(j)) break;
      if(j < d) break;
      sum += S[i] + S[j];
      res = max(res, sum);
    }
  }
  cout << res << endl;
}

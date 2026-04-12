#include<bits/stdc++.h>
using namespace std;

using I = long long;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> B(N, vector<int>(2));
  for(auto& i: B) cin >> i[0] >> i[1], sort(begin(i), end(i));
  sort(begin(B), end(B));

  I l = (*min_element(begin(B), end(B), [](auto l, auto r) {return l[1] < r[1];}))[1];
  I h = (*max_element(begin(B), end(B), [](auto l, auto r) {return l[1] < r[1];}))[1];
  I ans = (B[N-1][0]-B[0][0]) * (h-l);
  multiset<I> S;
  for(auto i: B) S.emplace(i[0]);
  I d = h - B[0][0];
  for(auto i: B) {
    S.erase(S.find(i[0]));
    S.emplace(i[1]);
    ans = min(ans, d*(*rbegin(S)-*begin(S)));
  }
  cout << ans << endl;
}

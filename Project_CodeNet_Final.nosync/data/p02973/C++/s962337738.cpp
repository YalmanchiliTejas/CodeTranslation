#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(auto& i: A) cin >> i;

  multiset<int> S;
  S.emplace(-1);
  for(auto a: A) {
    auto i = S.lower_bound(a);
    --i;
    if(i != begin(S)) S.erase(i);
    S.emplace(a);
  }
  cout << S.size() - 1 << endl;
}

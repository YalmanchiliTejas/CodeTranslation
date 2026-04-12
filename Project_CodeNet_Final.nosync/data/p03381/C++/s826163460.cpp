#include<bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for(auto& i: X) cin >> i;
  auto Y = X;
  sort(begin(Y), end(Y));
  auto l = Y[N/2 - 1], h = Y[N/2];
  for(auto x: X) cout << (x<=l ? h : l) << "\n";
}

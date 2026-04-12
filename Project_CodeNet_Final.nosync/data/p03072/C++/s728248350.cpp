#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,sum=0,lim=0;
  cin >> N;
  vector<int> H(N);
  
  for (auto&& x:H) {
    cin >> x;
  }
  lim = H.at(0);
  for (int i=0;i<N;i++) {
    if  (H.at(i) >= lim) {
      lim = H.at(i);
      sum++;
    } else {
      continue;
    }
  }
  cout << sum << endl;
}
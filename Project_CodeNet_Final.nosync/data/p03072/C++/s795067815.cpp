#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m = 0, o = 0;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++) {
    cin >> h.at(i);
    if(m <= h.at(i)) {
      o++;
      m = max(m, h.at(i));
    }
  }
  cout << o << endl;
}
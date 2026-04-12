#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A;
  cin >> A;
  int c = 0;
  rep(i, A.size() - 1) {
    if(A.at(i) == 'A' && A.at(i + 1) == 'C') {
      cout << "Yes" << endl;
      c++;
      break;
    }
  }
  if(c == 0) {
    cout << "No" << endl;
  }
}

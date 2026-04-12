#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <iomanip>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
using namespace std;

int N;
string s;

int main() {
  cin >> N >> s;
  vector<bool> ans(N);
  for (int i=0; i<4; i++) {
    if (i == 0) {
      ans.at(0) = true;
      ans.at(1) = true;
    } else if (i == 1) {
      ans.at(0) = true;
      ans.at(1) = false;
    } else if (i == 2) {
      ans.at(0) = false;
      ans.at(1) = true;
    } else {
      ans.at(0) = false;
      ans.at(1) = false;
    }
    for (int j=2; j<N; j++) {
      if (s.at(j-1) == 'o') {
        ans.at(j) = !(ans.at(j-1) ^ ans.at(j-2));
      } else {
        ans.at(j) = ans.at(j-1) ^ ans.at(j-2);
      }
    }
    // s = N-1
    if ((s.at(N-1) == 'o') ^ ans.at(N-1)) {
      if (ans.at(N-2) == ans.at(0)) {
        continue;
      }
    } else {
      if (ans.at(N-2) != ans.at(0)) {
        continue;
      }
    }
    // s = 0
    if ((s.at(0) == 'o') ^ ans.at(0)) {
      if (ans.at(N-1) == ans.at(1)) {
        continue;
      }
    } else {
      if (ans.at(N-1) != ans.at(1)) {
        continue;
      }
    }
    rep(j,N) {
      char c;
      if (ans.at(j)) {
        c = 'S';
      } else {
        c = 'W';
      }
      cout << c;
    }
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
}

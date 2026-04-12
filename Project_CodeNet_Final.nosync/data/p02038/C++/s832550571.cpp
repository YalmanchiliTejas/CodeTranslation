#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  while (cin >> n) {
    deque<char> q;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      q.push_back(c);
    }
    while (q.size() > 1) {
      char first = q[0]; q.pop_front();
      char second = q[0]; q.pop_front();
      char res;
      if (first == second) res = 'T';
      else res = 'T' + 'F' - first;
      q.push_front(res);
    }
    cout << q[0] << endl;
  }
  return 0;	
}

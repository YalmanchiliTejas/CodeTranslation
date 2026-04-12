#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
  string t, p;
  cin >> t >> p;
  int i, j;
  vector<int> a;
  for(i = j = 0; i < t.size() && j < p.size(); i++) {
    if (t[i] == p[j]) {
      j++;
      a.push_back(i);
    }
  }
  if (j != p.size()) {
    cout << "no" << endl;
    return 0;
  }
  string s = t, q = p;
  reverse(s.begin(), s.end());
  reverse(q.begin(), q.end());
  int k, l;
  vector<int> b;
  for(int k = l = 0; k < s.size() && l < q.size(); k++) {
    if (s[k] == q[l]) {
      l++;
      b.push_back(s.size() - k - 1);
    }
  }
  reverse(b.begin(), b.end());
  for (int m = 0; m < a.size(); m++) {
    if (a[m] != b[m]) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
}


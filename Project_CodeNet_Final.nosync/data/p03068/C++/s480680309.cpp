#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 7;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >>k; --k;
  for(int i = 0; i < n; ++i) {
    if(s[i] != s[k]) s[i] = '*';
  }
  cout << s << endl;
  return 0;
}

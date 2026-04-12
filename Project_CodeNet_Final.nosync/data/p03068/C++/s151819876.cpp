#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  char c = s.at(k - 1);
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) != c) {
      s.at(i) = '*';
    }
  }
  cout << s << endl;
}

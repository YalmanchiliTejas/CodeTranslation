#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
int main() {
  cin >> n >> s >> k;
  --k;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[k]) s[i] = '*';
  }
  cout << s << endl;
}

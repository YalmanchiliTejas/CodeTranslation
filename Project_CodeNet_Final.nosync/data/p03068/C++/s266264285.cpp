#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; string s; cin >> n >> s >> k;
  char c = s.at(k - 1);
  for (auto& e: s) if (e != c) e = '*';
  cout << s << endl;
}
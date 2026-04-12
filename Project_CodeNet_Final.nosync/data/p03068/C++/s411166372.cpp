#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  char target = s.at(k - 1);

  for(int i = 0; i < s.size(); i++) {
    if(s.at(i) != target) s.at(i) = '*';
  }
  cout << s << endl;
}

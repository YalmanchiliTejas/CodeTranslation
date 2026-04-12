#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  char s, t, u;
  cin >> s >> t >> u;
  
  if((s != t) || (t != u)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}

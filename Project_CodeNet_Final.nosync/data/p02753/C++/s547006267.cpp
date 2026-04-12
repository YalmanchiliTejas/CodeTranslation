#include <bits/stdc++.h>
using namespace std;
int main() {
  set<char> list;
  for (int i=0; i<3; i++) {
    char c;
    cin >> c;
    list.insert(c);
  }
  if (list.size() == 1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
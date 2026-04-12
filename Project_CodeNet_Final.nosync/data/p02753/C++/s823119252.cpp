#include <bits/stdc++.h>
using namespace std;

int main() {
  string x;
  cin >> x;
  if (x.at(0) == x.at(1) && x.at(1) == x.at(2) && x.at(0) == x.at(1)) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}

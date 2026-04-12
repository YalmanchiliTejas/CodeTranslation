#include <bits/stdc++.h>
using namespace std;

int main() {
  string r,g,b;
  cin >> r >> g >> b;
  if(atoi((g + b).c_str()) % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

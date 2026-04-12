#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c = a;
  vector<string> v(a);
  for (int i = 0; i < a; i++) cin >> v.at(i);
  for (int i = 0; i < c;) {
    bool flag = true;
    char k = v.at(i)[0];
    for (int j = 0; j < b; j++) {
      if (k != v.at(i)[j] || v.at(i)[j] == '#') flag = false;
    }
    if (flag) {
      v.erase(v.begin() + i);
      c--;
    }
    else i++;
  }
  
  for (int i = b - 1; i >= 0; i--) {
    bool flag = true;
    char k = v.at(0)[i];
    for (int j = 0; j < c; j++) {
      if (k != v.at(j)[i] || v.at(j)[i] == '#') flag = false;
    }
    if (flag) {
      for (int q = 0; q < c; q++) v.at(q).erase(v.at(q).begin() + i);
    }
  }
  
  for (int i = 0; i < c; i++) cout << v.at(i) << endl;
}
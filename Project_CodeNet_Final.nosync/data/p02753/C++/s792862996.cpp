#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool flag = false;
  if (s.at(0) != s.at(1))
    flag = true;
  if (s.at(1) != s.at(2))
    flag = true;
  if (s.at(2) != s.at(0))
    flag = true;
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
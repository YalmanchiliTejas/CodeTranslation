#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string r,g,b;
  cin >> r >> g >> b;

  int sum = stoi(r + g + b);
  if(sum % 4 == 0)
    cout << "YES" << endl;
  else cout << "NO" << endl;
}
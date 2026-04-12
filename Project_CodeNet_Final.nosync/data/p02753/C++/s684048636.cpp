#include <bits/stdc++.h>
using namespace std;
     
int main() {
  string a;
  cin >> a;
  
  if (a.at(0) != a.at(1) || a.at(0) != a.at(2) || a.at(1) != a.at(2)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string r;
  cin >> r;
  
  if(r.at(0)=='A'&&r.at(1)=='A'&&r.at(2)=='A')cout << "No" << endl;
  else{
  if(r.at(0)=='B'&&r.at(1)=='B'&&r.at(2)=='B')cout << "No" << endl;
  else cout << "Yes" << endl;
  }
  
}
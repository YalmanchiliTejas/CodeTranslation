#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<char>s(3);
  for(int i=0; i<3; i++){
    cin >> s.at(i);
  }
  if((s.at(0) == s.at(1)) && (s.at(1) == s.at(2)))
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
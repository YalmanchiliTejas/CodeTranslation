#include<bits/stdc++.h>
using namespace std;

int main () {
  string s;
  int a;
  cin >> s;
  
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'A') {
      a++;
    }
  }
  if (a==1 || a==2) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
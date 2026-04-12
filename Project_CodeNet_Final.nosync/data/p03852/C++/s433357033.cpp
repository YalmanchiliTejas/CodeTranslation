#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  string aiueo = "aiueo";
  cin >> c;
  
  int eval = 0;
  for (int i=0;i<5;i++) {
    if (c==aiueo.at(i)) {
      eval++;
    }
  }
  if (eval>0)
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}
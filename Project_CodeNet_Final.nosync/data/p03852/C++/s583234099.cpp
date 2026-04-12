#include <bits/stdc++.h>
using namespace std;

int main(){
  char a;
  cin >> a;
  string b="aiueo";
  bool flag=false;
  for (int i = 0; i < 5; i++) {
    if (a==b.at(i)) flag=true;
  }
  if(flag) cout << "vowel" << endl;
  else cout << "consonant" << endl;
}

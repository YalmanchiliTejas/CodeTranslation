#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  vector<string> vec;
  vec = {"a","i","u","e","o"};
  int a=0;
  for(int i=0;i<5;i++){
  	if(s==vec.at(i)) {
      a++;
      break;}
  }
  if(a==1) cout << "vowel" <<endl;
  else cout << "consonant" << endl;
}
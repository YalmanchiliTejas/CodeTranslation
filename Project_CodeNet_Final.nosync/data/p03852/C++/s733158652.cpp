#include <bits/stdc++.h>
using namespace std;

int main(){
  set<char> s;
  s.insert('a');
  s.insert('e');
  s.insert('i');
  s.insert('o');
  s.insert('u');
  char c;
  cin >> c;
  if(s.count(c)){
    cout << "vowel"  << endl;
  }else{
    cout << "consonant" << endl;
  }
  return 0;
}

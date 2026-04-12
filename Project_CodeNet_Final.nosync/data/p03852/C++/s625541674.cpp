#include <bits/stdc++.h>
using namespace std;
int main () {
  string s="aeiou";
  char c;
  cin>>c;
  for (int i=0;i<5;i++) {
    if (c==s.at(i)) {
      cout<<"vowel"<<endl;
      break;
    }
      if (i==4)
        cout<<"consonant"<<endl;
  }
}
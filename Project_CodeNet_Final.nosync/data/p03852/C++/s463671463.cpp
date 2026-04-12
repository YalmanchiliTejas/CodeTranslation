#include <bits/stdc++.h>
using namespace std;

int main() {
  string text="aiueo";
  char c,d;

  cin >> c;

  for(int i=0;i<5;i++){
      d=text.at(i);
      if(c==d){
          cout << "vowel" << endl;
        break;
      }
      else if(i==4){
          cout << "consonant" << endl;
      }
    }
}
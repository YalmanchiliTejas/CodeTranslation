#include <bits/stdc++.h>
using namespace std;

int main() {
  char s;
  bool judge=true;
  cin >> s;
    switch(s){  
      case'a':break;
      case'i':break;
        case'u':break;
        case'e':break;
        case'o':break;
      default:judge=false;
    }
    if(judge ==true)
      cout << "vowel" << endl;
  else cout << "consonant" << endl;
}

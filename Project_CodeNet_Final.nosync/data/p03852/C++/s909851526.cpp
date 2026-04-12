#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string str, a, i, u, e, o;
  a = "a"; i = "i"; u = "u"; e = "e"; o = "o";
  cin >> str;
  if(str == a || str == i || str == u || str == e || str == o){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }
}
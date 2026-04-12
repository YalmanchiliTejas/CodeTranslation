#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string S = "";
  
  if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'){
    S = "vowel";
  }else{
    S = "consonant";
  }
  cout << S << endl;
}

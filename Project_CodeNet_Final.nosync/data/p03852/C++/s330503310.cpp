#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string output = "consonant";
  char c;
  cin >> c;
  char vowel[5] = {'a','i','u','e','o'};
  for(v :vowel){
    if(c==v){
      output = "vowel";
      break;
    }
  }
  cout << output << endl;
}
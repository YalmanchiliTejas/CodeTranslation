#include <bits/stdc++.h>
using namespace std;

int main() {
  string C;
  cin >> C;
  
  string answer;
  
  for (int i = 0; i < C.size(); i++) {
    
    if (C.at(i) == 'a') {
      answer = "vowel";
      break;
    }
    else if (C.at(i) == 'e') {
      answer = "vowel";
      break;
    }
    else if (C.at(i) == 'i') {
      answer = "vowel";
      break;
    }
    else if (C.at(i) == 'o') {
      answer = "vowel";
      break;
    }
    else if (C.at(i) == 'u') {
      answer = "vowel";
      break;
    }
    else {
      answer = "consonant";
    }
    i++;
  }
  
  cout << answer << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  bool A = c == 'a';
  bool B = c == 'e';
  bool C = c == 'i';
  bool D = c == 'o';
  bool E = c == 'u';
  if(A||B||C||D||E){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }	
}


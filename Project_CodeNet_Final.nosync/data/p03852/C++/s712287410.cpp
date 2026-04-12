#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  string vowel = "aeiou";
    
  if(vowel.find(c) < 5){
    cout << "vowel" << endl;
  }
    
  else{
  	cout << "consonant" << endl;
  }
    
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void){
  string vowel = "aeiou";
  char c;
  cin >> c;
  for(int i = 0; i < 5; ++i){
    if(c == vowel[i]){
      cout << "vowel" << endl;
      return 0;
	} else {
      
    }
  }
  cout << "consonant" << endl;
  return 0;
}
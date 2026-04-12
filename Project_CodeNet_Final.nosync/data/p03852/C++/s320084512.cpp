#include <iostream>
using namespace std;

int main(){
  string boin = "aeiou";
  string result = "consonant";
  char c;
  cin >> c;

  for(int i = 0; i < boin.size(); i++){
    if(c == boin.at(i)){
      result = "vowel";
      break;
    }
  }

  cout << result << endl;
}
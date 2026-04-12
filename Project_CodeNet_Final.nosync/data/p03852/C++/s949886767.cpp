#include <iostream>
#include <string>
using namespace std;

int main(){
  string c;
  cin >> c;
  if(c == "a" or c == "i" or c == "u" or c == "e" or c == "o"){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }
  return 0;
}

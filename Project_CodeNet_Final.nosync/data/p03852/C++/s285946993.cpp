#include <iostream>
#include <string>

using namespace std;

int main(){

  string c;
  cin >> c;

  string v = "aiueo";

  if (v.find(c) != string::npos){
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }

  return 0;
}

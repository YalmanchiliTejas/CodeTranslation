#include <iostream>
#include <vector>

using namespace std;

int main(){
  string c;
  cin >> c;
  string B = "aiueo";
  if(B.find(c) != string::npos) {
   cout << "vowel" << endl;
  } else {
   cout << "consonant" << endl;
  }
 return 0;
} 

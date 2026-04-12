#include <iostream>
using namespace std;
 
int main(){
  char c;
  cin >> c;
  bool flg = false;
  char check[5] = {'a','i','u','e','o'};
  for(int i = 0; i < 5; ++i){
    if(c == check[i]){
      flg = true;
      break;
    }
  }
  cout << ((flg) ? "vowel" : "consonant") << endl; 
}

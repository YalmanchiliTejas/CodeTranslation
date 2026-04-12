#include <iostream>
using namespace std;
 
int main(){
  char set[] =  {'a', 'i', 'u', 'e', 'o'};
  char a;
  cin >> a;
  for(int i = 0; i < 5; i++){
    if(set[i] == a){
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}
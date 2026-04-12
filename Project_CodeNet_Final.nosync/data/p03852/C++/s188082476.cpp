#include <iostream>

using namespace std;

int main(void){
  char c; cin >> c;

  char judge[5] = {'a', 'i', 'u', 'e', 'o'};

  for(int i=0; i<5; i++)
    if(c == judge[i]){
      cout << "vowel" << endl;  
      return 0;
    }

  cout << "consonant" << endl;
  
  return 0;
}

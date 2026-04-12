#include <iostream>
using namespace std;
 
int main(){
  char alpabet;
  cin >> alpabet;
  
  if(alpabet == 'a' || alpabet == 'i' || 
     alpabet == 'u' || alpabet == 'e' || alpabet == 'o'){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }
}
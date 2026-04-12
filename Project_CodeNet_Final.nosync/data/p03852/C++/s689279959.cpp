#include <iostream>
using namespace std;

int main(){
  string c;
  cin >> c;

  if(c[0] == 'a' || c[0] == 'i' || c[0] == 'u' || c[0] == 'e'|| c[0] == 'o'){
    std::cout << "vowel" << std::endl;
  }else{
    std::cout << "consonant" << std::endl;
  }
}

#include <iostream>
#include <string>
 
int main() {
  std::string a;
  std::cin >>a;
  if(a == "a"||a == "i"||a=="u"||a=="e"||a=="o"){
    std::cout <<"vowel";
  }else{
    std::cout<<"consonant";
  }
}
#include <iostream>
 
int main() {
	std::string c, res;
  
  	std::cin >> c;
  
  if (c=="a" || c=="i" || c=="u" || c=="e" || c=="o" ) {
  	res = "vowel";
  } else {
    res = "consonant";
  }
  
  std::cout << res << std::endl;
}
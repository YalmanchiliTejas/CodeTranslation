#include <iostream> 
 
int main () {
	int n, rest, divRes;
  
  	std::cin >> n;
  
  	rest = n % 15;
  	divRes = (n - rest) / 15;
      
    std::cout << n * 800 - divRes * 200 << std::endl;
}
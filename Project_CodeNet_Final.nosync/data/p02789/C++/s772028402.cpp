#include <iostream>
 
int main() {
	int x, y;
  
  	scanf("%d", &x);
  	scanf("%d", &y);
  	
  	if (x == y) {
    	std::cout << "Yes" << std::endl;
      	return 0;
    }
  
  	std::cout << "No" << std::endl;
    return 0;
}
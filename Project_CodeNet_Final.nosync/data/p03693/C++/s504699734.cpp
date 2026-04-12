#include <iostream>

int main()
{
  	int r, g, b;
  	std::cin >> r >> g >> b;
  	if((2 * g + b) % 4 == 0){
      	std::cout << "YES";
    }else{
      	std::cout << "NO";
    }
	return 0;
}
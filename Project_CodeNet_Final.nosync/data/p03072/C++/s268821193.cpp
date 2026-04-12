#include <iostream>

int main() {
	int N;
  	std::cin >> N;
  	
  	int cnt = 1;
  	int max = 0;
  	std::cin >> max;
  	for (int i = 1; i < N; ++i) {
        int height = 0;
      	std::cin >> height;
      	if (height >= max) {
        	max = height;
          	++cnt;
        }
    }
  	std::cout << cnt << std::endl;
  
	return 0;
}
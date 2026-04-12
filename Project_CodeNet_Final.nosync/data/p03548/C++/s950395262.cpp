#include <iostream>

 int main() {

	 int x;
	 int y;
	 int z;
	 int n = 0;

	 std::cin >> x >> y >> z;

	 x -= z;

	 while (true) {
		 x -= y;
		 x -= z;
		
		 if (x < 0) {
			 break;
		 }

		 n += 1;
	 }

	 std::cout << n << std::endl;

	 return 0;

}
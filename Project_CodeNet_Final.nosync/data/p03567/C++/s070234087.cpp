#include <iostream>
#include <string>

 int  main() {
	 std::string s;
	 while (std::cin >> s) {

		 if (s.find("AC") == -1) {
			 std::cout << "No" << std::endl;
		 }
		 else {
			 std::cout << "Yes" << std::endl;
		 }
	 }
}
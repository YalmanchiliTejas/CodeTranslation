#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>



int main(){

	int X, Y,Z;

	std::cin >> X >> Y >> Z;

	int count =0;
	while((Y+Z)*count+Z<=X){
		count++;
	}
	std::cout << count-1 <<std::endl;
	return 0;

} 
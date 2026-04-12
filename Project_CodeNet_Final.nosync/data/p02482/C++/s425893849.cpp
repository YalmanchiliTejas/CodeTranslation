#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(void){
	int a,b = 0;
	int ans1,ans2;


	std::cin >> a >> b;
	ans1 = a-b;
	if(ans1 == 0){
		std::cout << "a == b\n";
	}else if(ans1 > 0){
		std::cout << "a > b\n";
	}else{
		std::cout << "a < b\n";
	}

	return 0;
}
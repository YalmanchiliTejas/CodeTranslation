#include<iostream>
#include<string>

int main(){

	int a, b;
	std::string str;
	std::cin >> a >> b;

	if (a > b)str = ">";
	else if (a < b)str = "<";
	else str = "==";

	std::cout << "a " << str << " b" << std::endl;

	return 0;
}
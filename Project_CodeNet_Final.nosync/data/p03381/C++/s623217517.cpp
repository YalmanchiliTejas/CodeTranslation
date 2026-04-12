#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>



void getInput(std::vector<int> *v);

int main(void)
{
	// input
	std::vector<int> v;
	getInput(&v);
	getInput(&v);
	
	/*
	for(int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	*/
	

	// solve
	int num = v[0];
	v.erase(v.begin());

	std::vector<int> _v = v;

	std::sort(v.begin(), v.end());

	int n1 = v[num/2 - 1];
	int n2 = v[num/2];

	for(int i = 0; i < num; i++) {
		if(_v[i] <= n1) std::cout << n2 << std::endl;
		else std::cout << n1 << std::endl;
	}











	return 0;
}




void getInput(std::vector<int> *v)
{
	std::string s, buf;
	std::getline(std::cin, s);
	std::stringstream ss(s);
	
	while(std::getline(ss, buf, ' ')) {
		(*v).push_back(std::stoi(buf));
	}
	
}



















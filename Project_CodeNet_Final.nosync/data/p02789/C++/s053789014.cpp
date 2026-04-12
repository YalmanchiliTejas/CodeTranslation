#include<iostream>
//#include<vector>

int main(){
	int n,m;
	std::cin>>n>>m;

	if (n == m) {
		std::cout <<"Yes" << std::endl;
		exit(0);
	}

	std::cout << "No" << std::endl;


	return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

int main(){
	int ans;
	int n;

	std::cin>>n;

	if(n==3 || n==5 || n==7)
		std::cout<<"YES"<<std::endl;
	else
		std::cout<<"NO"<<std::endl;



	return 0;
}
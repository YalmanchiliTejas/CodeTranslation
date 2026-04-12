#include<iostream>
int main()
{
	int N;
	std::cin>>N;
	const int x=800*N;
	const int y=N/15*200;
	std::cout<<x-y<<std::endl;
	return 0;
}
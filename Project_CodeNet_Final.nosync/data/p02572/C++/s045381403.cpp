#include<iostream>
#include<vector>
#include<numeric>

int main()
{	unsigned long long n;
	std::cin >> n ;
	std::vector<unsigned long long> vec;

	for(unsigned int i = 0; i < n ; ++i)
	{
		unsigned long long q;
		std::cin >> q ;
		vec.push_back(q);
	}
	unsigned long long local_sum = 0;	
	unsigned long long sum=0;
	for(unsigned int i = 0 ; i < vec.size(); ++i)
	{
		sum += local_sum*vec[i];
		sum %= 1000000007;
		local_sum += vec[i];
		local_sum%= 1000000007;		
	}
	std::cout << sum%1000000007 << std::endl;
	
}

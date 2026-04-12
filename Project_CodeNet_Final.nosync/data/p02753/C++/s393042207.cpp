#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
using namespace std;
namespace adaptor = boost::adaptors;

void Main()
{
	string S;
   
   	cin >> S;
  
    if(S[0] == S[1] && S[1] == S[2])
      printf("No");
  
    else
      printf("Yes");
 	
 	
}
 
int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
  Main();
}


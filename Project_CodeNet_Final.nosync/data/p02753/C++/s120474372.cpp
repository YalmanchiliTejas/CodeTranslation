#include <iostream>
#include <string>

int main(){
	std::string S;
	std::cin >> S;
  
  	if(S == "AAA" || S == "BBB"){
    	std::cout << "No" << std::endl; 
    }
  	else{
    	std::cout << "Yes" << std::endl;
    }
  
  	return 0;
}
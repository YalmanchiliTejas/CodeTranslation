#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    bool ac = false;
	string s;
	std::cin >> s;
	for (int i = 0; i < s.size(); i++) {
	    if(s[i] == 'A' and s[i + 1] == 'C'){
	        std::cout << "Yes" << std::endl;
	        ac = true;
	        break;
	    }
	}
	if(ac == false){
	    std::cout << "No" << std::endl;
	}
	return 0;
}
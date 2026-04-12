#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <functional>

int main() {
	int n;
	std::cin >> n;
	if(n==3 || n==5 || n==7){
		std::cout << "YES";
	}else{
		std::cout << "NO";
	}
	std::cout << std::endl;
}
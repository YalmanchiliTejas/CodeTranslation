#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> h(n);
	int hmax=0;
	int count = 0;
	for(int i=0; i<n; i++){
		std::cin >> h[i];
		if(hmax<=h[i]){
			count++;
			hmax = h[i];
		}
	}
	std::cout << count <<std::endl;
	return 0;
}

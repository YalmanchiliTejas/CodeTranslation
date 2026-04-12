#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> h;
    for(int i=0;i<n;i++){
	int h_i;
	std::cin >> h_i;
	h.push_back(h_i);
    }
    int sum = 0;
    int max = 0;
    for(int i=0;i<n;i++){
	if(max <= h[i]) {
	    sum++;
	    max = h[i];
	}
    }
    std::cout << sum << std::endl;
}

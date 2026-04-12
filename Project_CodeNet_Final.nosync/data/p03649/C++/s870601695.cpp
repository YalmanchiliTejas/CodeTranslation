#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>

int main(void){
	int N;
	uint64_t a[50][2];
	std::cin >> N;
	for(int i=0;i<N;i++)std::cin >> a[i][0];
	uint64_t ans = 0;
	while(true){
		bool end = true;
		for(int i=0;i<N;i++)if(a[i][0] >= N)end = false;
		if(end)break;
		uint64_t sum = 0;
		for(int i=0;i<N;i++){
			uint64_t x = a[i][0] / N;
			sum += x;
			a[i][1] = x;
			a[i][0] = a[i][0] % N;
		}
		ans += sum;
		for(int i=0;i<N;i++){
			a[i][0] += sum - a[i][1];
		}
	}
	std::cout << ans << std::endl;
}

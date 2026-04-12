#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cmath>
#include<fstream>
#include<numeric>

int main(){
	int N;
	std::vector<int> H;
	int max=0;
	int cnt=0;

	std::cin >> N;
	for(int i=0;i<N;i++){
		int h;
		std::cin >> h;
		if(max<h) max=h;
		if(max<=h) cnt++;
	}

	std::cout << cnt << std::endl;

	return 0;
}

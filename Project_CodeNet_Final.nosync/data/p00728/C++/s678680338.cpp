#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	int n;
	while(std::cin >> n, n){
		std::vector<int> v;
		for(int i=0;i<n;i++){
			int j;
			std::cin >> j;
			v.push_back(j);
		}
		std::sort(v.begin(), v.end());
		int ave = 0;
		for(int i=1;i<v.size()-1;i++){
			ave += v[i];
		}
		ave /= n-2;
		std::cout << ave << std::endl;
	}
}
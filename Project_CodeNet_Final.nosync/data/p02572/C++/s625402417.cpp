#include<iostream>
#include<vector>
#include<cmath>


int main(){

	int N;
	unsigned long long int ans = 0;
	std::cin >> N;

	std::vector<unsigned long long int> list(N,0);

	unsigned long long int sum=0;

	for (int i = 0; i < N;i++){
		std::cin >> list[i];
		sum += list[i];
	}


	for (int i = 0; i < N-1; i++){
		ans += ((list[i]%1000000007) * ((sum-=list[i])%1000000007));
		ans %= 1000000007;
	}

	std::cout << ans << std::endl;
}
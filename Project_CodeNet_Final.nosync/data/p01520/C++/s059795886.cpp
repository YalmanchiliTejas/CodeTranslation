#include<iostream>
int main(){
	int N,n, T, E,high,low;
	std::cin >> N >> T >> E;
	high = T + E;
	low = T - E;
	for (int i = 0; i < N; i++){
		std::cin >> n;
		if (high / n != 0){
			if (n*(high/n)>=low){
				std::cout << i + 1<<"\n";
				return 0;
			}
		}
	}
	std::cout << -1 << "\n";

}
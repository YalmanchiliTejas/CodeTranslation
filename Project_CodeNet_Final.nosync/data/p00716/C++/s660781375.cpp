#include<iostream>

int first, year, n, type, every;
double rate;

int calculate(){
	int a = first, b = 0;
	if(type == 0){
		for(int i=0;i<year;i++){
			b += a * rate;
			a -= every;
		}
		return a + b;
	}
	for(int i=0;i<year;i++){
		a += a * rate - every;
	}
	return a;
}

int main(){
	int m;
	std::cin >> m;
	while(m--){
		std::cin >> first >> year >> n;
		int res = 0;
		for(int i=0;i<n;i++){
			std::cin >> type >> rate >> every;
			res = std::max(res, calculate());
		}

		std::cout << res << std::endl;
	}
}
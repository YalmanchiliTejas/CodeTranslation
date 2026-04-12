#include <iostream>

int main(){
	int n, m, max;
	char s;

	while(std::cin >> n >> m, n&&m){
		max = n + m, s = 'A';
		for(int i=0;i<4;i++){
			std::cin >> n >> m;
			if(n + m > max)max = n + m, s = 'B' + i;
		}

		std::cout << s << " " << max << '\n';
	}
}
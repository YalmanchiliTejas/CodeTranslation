#include <iostream>

int main() {
	while (1) {
		int N;
		int s[100];
		std::cin >> N;
		if ( N == 0 ) break;
		for ( int i=0; i<N; i++ ) {
			std::cin >> s[i];
		}
		int min=s[0], max=s[0], sum=0;
		for ( int i=0; i<N; i++ ) {
			if ( min > s[i] ) min = s[i];
			if ( max < s[i] ) max = s[i];
			sum += s[i];
		}
		std::cout << (int)((sum-min-max)/(N-2)) << std::endl;
	}
	return 0;
}
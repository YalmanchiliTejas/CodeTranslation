#include <iostream>
#include <string>

int main(void)
{
	int m;
	std::cin >> m;

	for ( int i = 0; i < m; ++i ) {
		int sikin, nen, n;

		std::cin >> sikin >> nen >> n;

		int max = 0;
		for ( int j = 0;j < n; ++j ) {
			int hukuri = 0;
			double rate;
			int cost;

			std::cin >> hukuri >> rate >> cost;

			if ( hukuri == 1 ) {
				int A = sikin, B = 0;
				for ( int i = 0; i < nen; ++i ) {
					B = A * rate;
					A = A + B - cost;
				}
				if ( A > max ) max = A;
			} else {
				int A = sikin, B = 0;
				for ( int i = 0; i < nen; ++i ) {
					B += A * rate;
					A = A - cost;
				}
				if ( A + B > max ) max = A+B;
			}
		}
		std::cout << max << std::endl;
	}
	return 0;
}
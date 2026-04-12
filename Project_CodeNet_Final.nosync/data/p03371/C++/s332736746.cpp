#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <array>
#include <string.h>
#include <vector>




int main() {
	int A,B,C,X,Y;

	scanf("%d %d %d %d %d", &A,&B,&C,&X,&Y);
	
	int sum = 0;
	int sum2 = 0;
	int sum3 = 0;

	sum = A * X + B * Y;

	if (X > Y) {
		int tmp = X;
		X = Y;
		Y = tmp;
		tmp = A;
		A = B;
		B = tmp;
	}
	
	sum2 = C * 2*X + B * (Y - X);

	sum3 = C * 2 * Y;




	printf("%d", std::min(sum, std::min(sum2, sum3)));

	return 0;
}